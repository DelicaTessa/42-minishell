/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 08:14:19 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/31 12:16:17 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
