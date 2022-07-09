/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_pass.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 22:32:53 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 21:25:22 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <libft.h>
#include <ms_debug_utils.h>

t_err	syntax_err(t_token_type type)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
	if (type == TOK_PIPE)
		ft_putstr_fd("'|'\n", 2);
	else if (type == TOK_REDIR_IN)
		ft_putstr_fd("'<'\n", 2);
	else if (type == TOK_REDIR_OUT)
		ft_putstr_fd("'>'\n", 2);
	else if (type == TOK_APPEND)
		ft_putstr_fd("'>>'\n", 2);
	else if (type == TOK_HERE_DOC)
		ft_putstr_fd("'<<'\n", 2);
	return (SYNTAX_ERR);
}

//t_err	something_wrong(t_token_list *list)
//{
//	if (!list->prev && !list->next)
//		return (syntax_err(TOK_PIPE));
//	if (list->prev && list->prev->type == TOK_PIPE)
//	{
//		ft_putstr_fd("minishell: syntax error near ", 2);
//		ft_putstr_fd("unexpected token '|'\n", 2);
//	}
//	else if (list->next && list->next->type == TOK_PIPE)
//	{
//		ft_putstr_fd("minishell: syntax error near ", 2);
//		ft_putstr_fd("unexpected token '|'\n", 2);
//	}
//	else
//		syntax_err(TOK_PIPE);
//	return (SYNTAX_ERR);
//}

t_err	pipe_syntax_pass(t_token_list *list)
{
	while (list)
	{
		if (list->type == TOK_PIPE)
		{
			if (!list->prev || !list->next)
				return (syntax_err(TOK_PIPE));
			if (list->prev->type == TOK_PIPE || \
				list->next->type == TOK_PIPE)
				return (syntax_err(TOK_PIPE));
		}
		list = list->next;
	}
	return (NO_ERROR);
}

t_err	redir_syntax_pass(t_token_list *list)
{
	while (list)
	{
		if (list->type == TOK_PIPE)
			break ;
		else if (list->type == TOK_REDIR_IN || list->type == TOK_REDIR_OUT \
				|| list->type == TOK_APPEND || list->type == TOK_HERE_DOC)
		{
			if (!list->next || list->next->type != TOK_WORD)
				return (syntax_err(list->type));
			else
				list = list->next;
		}
		else if (list->type == TOK_WORD)
			(void)list;
		else
			printf(RED "[redir_syntax_pass Wrong tok_type?: %s\n" \
				RESET, get_token_str(list->type));
		list = list->next;
	}
	return (NO_ERROR);
}
