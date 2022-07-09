/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 14:17:53 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/31 12:16:36 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = ft_calloc(ft_strlen(src) + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}
