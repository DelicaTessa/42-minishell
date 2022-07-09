/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/06 14:09:15 by tclement      #+#    #+#                 */
/*   Updated: 2021/05/04 08:30:24 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *begin_list, void (*free_fct)(void **))
{
	t_list	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		free_fct((void **)&begin_list);
		begin_list = tmp;
	}
}
