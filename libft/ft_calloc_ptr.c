/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 13:40:54 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/07 23:49:34 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_calloc_ptr(size_t count, size_t size, void **ptr)
{
	size_t	i;

	count++;
	*ptr = malloc(count * size);
	if (!*ptr)
		return (0);
	i = 0;
	while (i < size * count)
	{
		((unsigned char *)(*ptr))[i] = '\0';
		i++;
	}
	return (1);
}
