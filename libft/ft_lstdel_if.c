/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel_if.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/03 15:39:41 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/31 12:12:41 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_if(t_list **begin_list, void *data_ref,
							int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*prev;

	list_ptr = *begin_list;
	prev = NULL;
	while (list_ptr)
	{
		if (!cmp(list_ptr->data, data_ref))
		{
			if (prev)
				prev->next = list_ptr->next;
			else
				*begin_list = (*begin_list)->next;
			(*free_fct)(list_ptr->data);
			ft_free_dbl_ptr((void **)&list_ptr);
			if (!prev)
				list_ptr = (*begin_list);
			else
				list_ptr = prev->next;
			continue ;
		}
		prev = list_ptr;
		list_ptr = list_ptr->next;
	}
}
