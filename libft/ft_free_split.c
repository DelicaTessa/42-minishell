/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_split.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 12:20:21 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/07 23:50:30 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_split(char ***split)
{
	int	i;

	i = 0;
	if (!*split)
		return ;
	while ((*split)[i])
	{
		free((*split)[i]);
		(*split)[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
}
