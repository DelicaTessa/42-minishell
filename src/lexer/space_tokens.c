/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   space_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:31 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:34:39 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <datatypes.h>
#include <token_utils.h>

t_err	space_token(const char *line, int *i, t_token_list **list)
{
	t_token_list	*new_token;
	int				j;

	j = 0;
	while (ft_isspace(line[j]))
		j++;
	new_token = create_token(TOK_SPACE, NULL);
	if (!new_token)
		return (MALLOC_FAIL);
	add_to_tokenlist(list, new_token);
	*i = *i + j;
	return (NO_ERROR);
}
