/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstpush_back.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 08:19:33 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/31 12:16:06 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **begin_list, void *data)
{
	t_list	*current;

	if (*begin_list == NULL)
	{
		*begin_list = ft_lstnew(data);
		return ;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = ft_lstnew(data);
}
