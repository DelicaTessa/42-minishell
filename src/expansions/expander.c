/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:31 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 23:18:26 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <libft.h>
#include <expander.h>
#include <variable_expander.h>
#include <expander_utils.h>
#include <expander_token_utils.h>

t_err	word_join(t_token_list **list, t_envi *info, t_token_type type)
{
	t_err			rv;
	t_token_list	*node;

	(void)info;
	(void)type;
	node = *list;
	if (!node)
		return (printf("[word_join] Empty token_list?\n"));
	while (node->next)
	{
		if (node->type == TOK_WORD && node->next->type == TOK_WORD)
		{
			if (node->prev == NULL)
				rv = join_head_token(list, TOK_WORD);
			else
				rv = join_token(node, TOK_WORD);
			if (rv == MALLOC_FAIL)
				return (MALLOC_FAIL);
			node = *list;
		}
		else
			node = node->next;
	}
	return (NO_ERROR);
}

t_err	expander(char *line, t_curr_input *input, t_envi *info)
{
	int							i;
	t_err						rv;
	t_token_list				**list;
	static t_expander_funptr	expander_funptr[4] = {
	[0] = rm_double_tokens,
	[1] = quotes_to_words,
	[2] = expand_dollars,
	[3] = word_join
	};

	(void)line;
	i = 0;
	rv = NO_ERROR;
	list = &input->lexer;
	while (rv == NO_ERROR && i < 4)
	{
		if (!*list)
			return (EMPTY);
		rv = expander_funptr[i](list, info, TOK_DOLLAR);
		i++;
	}
	if (rv != NO_ERROR)
		return (rv);
	rm_token_type(list, info, TOK_SPACE);
	return (NO_ERROR);
}
