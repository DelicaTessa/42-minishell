/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   variable_expander.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:11:08 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:44:48 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <variable_expander_utils.h>
#include <expander_token_utils.h>
#include <more_exp_token_utils.h>
#include <builtin_utils.h>
#include <lexer_utils.h>
#include <token_utils.h>

t_err	expand_d_tailbit(t_token_list **head, char *key, char *data)
{
	t_token_list	*var_token;

	if (ft_strlen(data) > ft_strlen(key))
	{
		var_token = create_tailpart(key, data);
		if (!var_token)
		{
			free (key);
			return (MALLOC_FAIL);
		}
		replace_token(*head, var_token);
	}
	else
	{
		if ((*head)->prev)
			cut_token(*head);
		else
			cut_head_token(head);
	}
	return (NO_ERROR);
}

t_err	insert_full_string(t_token_list **head, char *key, char *data)
{
	int				len;
	char			*str;
	t_token_list	*var_token;

	free(key);
	len = ft_strlen(data);
	str = ft_calloc(len + 2, 1);
	if (!str)
		return (MALLOC_FAIL);
	create_full_string(&str, data, len);
	var_token = create_token(TOK_WORD, str);
	if (!var_token)
	{
		free(str);
		return (MALLOC_FAIL);
	}
	if ((*head)->prev)
		replace_token(*head, var_token);
	else
		replace_head_token(head, var_token);
	return (NO_ERROR);
}

t_err	expand_d(t_token_list **head, t_envi *info, char *key, char *data)
{
	char			*value;

	if (get_env_key(data, &key) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_strncmp(data, "?", 1) == 0)
		value = ft_itoa(info->exitcode);
	else if (!char_is_allowed(data[0], "/=."))
		return (insert_full_string(head, key, data));
	else if (get_env_value(info->ms_envp, key, &value) == MALLOC_FAIL)
	{
		free(key);
		return (MALLOC_FAIL);
	}
	if (value)
		return (insert_tokens(head, key, value, data));
	if (expand_d_tailbit(head, key, data) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	free (key);
	return (NO_ERROR);
}

t_err	prep_expand_d(t_token_list **head, t_envi *info, char *key)
{
	t_token_list	*next;
	char			*data;

	data = (*head)->next->data;
	next = (*head)->next;
	if ((*head)->prev)
	{
		cut_token(*head);
		return (expand_d(&next, info, key, data));
	}	
	cut_head_token(head);
	return (expand_d(head, info, key, data));
}

t_err	expand_dollars(t_token_list **list, t_envi *info, t_token_type type)
{
	char			*key;
	t_token_list	*node;
	t_token_list	*temp;
	t_err			rv;

	(void)type;
	key = NULL;
	node = *list;
	while (node)
	{
		if (node->type == 4 && node->next && node->next->type == TOK_WORD)
		{
			temp = node->next->next;
			if (node->prev)
				rv = prep_expand_d(&node, info, key);
			else
				rv = prep_expand_d(list, info, key);
			if (rv == MALLOC_FAIL)
				return (MALLOC_FAIL);
			node = temp;
		}
		else
			node = node->next;
	}
	return (NO_ERROR);
}
