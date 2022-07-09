/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:19 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:43:07 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <lexer.h>

t_err	syntax_err_lexer(char token)
{
	ft_putstr_fd("minishell: syntax error unexpected token '", 2);
	if (token == (char)DOUBLE_PIPE)
		ft_putstr_fd("||", 2);
	else
		ft_putchar_fd(token, 2);
	ft_putstr_fd("' (unsupported)\n", 2);
	return (SYNTAX_ERR);
}

t_bool	char_is_allowed(int c, char *not_allowed)
{
	if (ft_strchr(not_allowed, c))
		return (FALSE);
	return (TRUE);
}

void	clean_lexer(t_token_list **list)
{
	t_token_list	*node;
	t_token_list	*temp;

	node = *list;
	if (!node)
		return ;
	while (node)
	{
		temp = node;
		ft_free_str(&node->data);
		node = temp->next;
		free (temp);
	}
	*list = NULL;
}
