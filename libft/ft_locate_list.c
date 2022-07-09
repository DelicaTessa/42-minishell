/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_locate_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 08:24:46 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/31 12:13:51 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_locate_list(t_list *begin_list, unsigned int nbr)
{
	if (!begin_list)
		return (NULL);
	while (begin_list->next && nbr)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	if (nbr)
		return (NULL);
	return (begin_list);
}
