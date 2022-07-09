/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:48 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:45:57 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>

void	ft_free_partial_split(char ***split, int failed_i)
{
	int	i;

	i = 0;
	while (i < failed_i)
	{
		free ((*split)[i]);
		i++;
	}
	free (*split);
	*split = NULL;
}

char	**make_split(t_token_list *list, int word_amount)
{
	char	**split;
	int		i;

	(void)list;
	split = ft_calloc(word_amount + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_amount)
	{
		split[i] = ft_strdup(list->data);
		if (!split[i])
		{
			ft_free_partial_split(&split, i);
			return (NULL);
		}
		list = list->next;
		i++;
	}
	return (split);
}

char	**create_cmd_split(t_token_list *list, int word_count)
{
	int		i;
	char	**split;

	split = ft_calloc(word_count + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (list && list->type != TOK_PIPE)
	{
		if (list->type == TOK_WORD && !list->is_parsed)
		{
			split[i] = ft_strdup(list->data);
			if (!split[i])
			{
				ft_free_partial_split(&split, i);
				return (NULL);
			}
			i++;
		}
		list = list->next;
	}
	return (split);
}
