/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipspace.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 23:13:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/31 12:18:54 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skipspace(char const *str)
{
	while (ft_isspace(*str))
		str++;
	return ((char *)str);
}
