/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_array_dup.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 17:24:52 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/31 12:17:03 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_array_dup(char ***strs, size_t size, char *str)
{
	*strs = (char **)ft_calloc(size + 1, sizeof(**strs));
	if (!(*strs))
		return (0);
	*strs[0] = ft_strdup(str);
	if (!(*strs[0]))
	{
		ft_free_dbl_ptr((void **)&(*strs));
		return (0);
	}
	return (1);
}
