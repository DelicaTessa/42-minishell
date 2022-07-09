/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 13:31:44 by tclement      #+#    #+#                 */
/*   Updated: 2021/05/05 11:27:53 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	len = s1_len + s2_len + 1;
	dst = ft_calloc(len, sizeof(*dst));
	if (!dst)
		return (NULL);
	if (s1)
		dst = ft_memcpy(dst, s1, s1_len + 1);
	ft_strlcat(dst, s2, len);
	return (dst);
}
