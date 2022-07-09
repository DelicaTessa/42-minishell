/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_array_len.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 17:53:46 by tclement      #+#    #+#                 */
/*   Updated: 2021/05/03 17:53:59 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_array_len(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
