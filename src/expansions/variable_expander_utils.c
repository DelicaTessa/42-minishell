/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   variable_expander_utils.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:48:09 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:45:01 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <token_utils.h>
#include <more_exp_token_utils.h>

void	create_full_string(char **str, char *data, int len)
{
	(*str)[0] = '$';
	while (len >= 0)
	{
		(*str)[len + 1] = data[len];
		len--;
	}
}

t_token_list	*create_tailpart(char *key, char *data)
{
	char	*str;

	str = ft_strdup(data + ft_strlen(key));
	if (!str)
		return (NULL);
	return (create_token(TOK_WORD, str));
}

t_err	do_normalstuff(t_token_list *list, char *key, char *value, char *data)
{
	t_token_list	*var_token;
	t_token_list	*temp;

	var_token = create_token(TOK_WORD, value);
	if (!var_token)
	{
		free(key);
		free(value);
		return (MALLOC_FAIL);
	}
	temp = var_token;
	replace_token(list, var_token);
	if (ft_strlen(data) > ft_strlen(key))
	{
		var_token = create_tailpart(key, data);
		if (!var_token)
			return (MALLOC_FAIL);
		insert_token_after(temp, var_token);
	}
	free (key);
	return (NO_ERROR);
}

t_err	do_headstuff(t_token_list **head, char *key, char *value, char *data)
{
	t_token_list	*var_token;
	t_token_list	*temp;

	var_token = create_token(TOK_WORD, value);
	if (!var_token)
	{
		free(value);
		return (MALLOC_FAIL);
	}
	temp = var_token;
	replace_head_token(head, var_token);
	if (ft_strlen(data) > ft_strlen(key))
	{
		var_token = create_tailpart(key, data);
		if (!var_token)
			return (MALLOC_FAIL);
		insert_token_after(temp, var_token);
	}
	free(key);
	return (NO_ERROR);
}

t_err	insert_tokens(t_token_list **head, char *key, char *value, char *data)
{
	char	*data_dup;
	t_err	err;

	data_dup = ft_strdup(data);
	if (!data_dup)
		return (MALLOC_FAIL);
	if ((*head)->prev)
		err = do_normalstuff(*head, key, value, data_dup);
	else
		err = do_headstuff(head, key, value, data_dup);
	free(data_dup);
	return (err);
}
