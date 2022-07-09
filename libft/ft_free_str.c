/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 15:02:04 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/31 12:18:17 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_str(char **str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}
