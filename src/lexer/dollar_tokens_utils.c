/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dollar_tokens_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:56:22 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:44:03 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <token_utils.h>

t_err	put_dquote_token(const char *dquote, t_token_list **list, int j)
{
	char	*word;

	word = ft_substr(dquote, 0, j);
	if (!word)
		return (MALLOC_FAIL);
	if (add_new_token_to_list(list, TOK_QUOTE, word) == MALLOC_FAIL)
	{
		free (word);
		return (MALLOC_FAIL);
	}
	return (NO_ERROR);
}
