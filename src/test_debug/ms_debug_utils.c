/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_debug_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:25:48 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 17:27:01 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <datatypes.h>

char	*get_tree_str(t_nodetype type)
{
	static char	*strings[7] = {
		"PIPE",
		"NO_PIPE",
		"REDIR_IN",
		"REDIR_OUT",
		"APPEND",
		"HERE_DOC",
		"CMD"
	};

	return (strings[type]);
}

char	*get_token_str(t_token_type type)
{
	static char	*strings[12] = {
		"WORD",
		"PIPE",
		"QUOTE",
		"DQUOTE",
		"DOLLAR",
		"REDIR_IN",
		"REDIR_OUT",
		"APPEND",
		"HERE_DOC",
		"SPACE",
		"EMPTY_WORD",
		"TOK_ERROR"
	};

	return (strings[type]);
}
