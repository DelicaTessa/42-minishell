/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_dbl_ptr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 17:45:32 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/07 23:49:43 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_dbl_ptr(void **ptr)
{
	if (!(*ptr))
		return ;
	free(*ptr);
	*ptr = NULL;
}
