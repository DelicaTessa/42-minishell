/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:10:00 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 16:10:52 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <datatypes.h>
#include <expander_token_utils.h>

t_err	quotes_to_words(t_token_list **list, t_envi *info, t_token_type type)
{
	t_token_list	*node;

	(void)info;
	(void)type;
	node = *list;
	if (!node)
		return (EMPTY);
	while (node)
	{
		if (node->type == TOK_QUOTE || node->type == TOK_DQUOTE)
			node->type = TOK_WORD;
		node = node->next;
	}
	return (NO_ERROR);
}

t_err	rm_token_type(t_token_list **list, t_envi *info, t_token_type type)
{
	t_token_list	*node;
	t_token_list	*temp;

	(void)info;
	node = *list;
	while (node)
	{
		temp = node->next;
		if (node->type == type)
		{
			if (node->prev)
				cut_token(node);
			else
				cut_head_token(list);
		}
		node = temp;
	}
	return (NO_ERROR);
}

t_err	rm_double_tokens(t_token_list **list, t_envi *info, t_token_type type)
{
	t_token_list	*node;
	t_token_list	*temp;

	(void)info;
	node = *list;
	if (!node)
		return (EMPTY);
	while (node && node->next)
	{
		temp = node->next;
		if (node->type == type && node->next->type == type)
		{
			if (node->prev)
				cut_token(node);
			else
				cut_head_token(list);
		}
		node = temp;
	}
	return (NO_ERROR);
}
