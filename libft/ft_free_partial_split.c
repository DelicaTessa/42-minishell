/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_partial_split.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 21:24:22 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/31 12:25:25 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_partial_split(char ***split, int failed_i)
{
	int	i;

	i = 0;
	while (i < failed_i)
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
	*split = NULL;
}
