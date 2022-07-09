/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_exp_token_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:08:39 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:45:14 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <token_utils.h>

void	insert_token_after(t_token_list *list, t_token_list *new)
{
	if (!list)
		printf(RED "[insert_token_after] empty list?!\n" RESET);
	else if (!new)
		printf(RED "[insert_token_after] empty (new)list?!\n" RESET);
	else
	{
		new->next = list->next;
		if (list->next)
			list->next->prev = new;
		list->next = new;
		new->prev = list;
	}
}

void	replace_head_token(t_token_list **head, t_token_list *new)
{
	if (!*head)
		return ((void)printf(RED "[replace_head_token] no head..\n" RESET));
	if ((*head)->prev)
		return ((void)printf(RED "[replace_head_token] not a head?\n" RESET));
	if ((*head)->next)
	{
		new->next = (*head)->next;
		(*head)->next->prev = new;
	}
	del_token(*head);
	*head = new;
}

void	replace_token(t_token_list *list, t_token_list *new)
{
	if (!list)
		return ((void)printf(RED "[replace_token] no token_list..\n" RESET));
	if (!list->prev)
		return ((void)printf(RED "[replace_token] no prev in \
			token_list..\n" RESET));
	new->next = list->next;
	if (list->next)
		list->next->prev = new;
	new->prev = list->prev;
	if (list->prev)
		list->prev->next = new;
	del_token(list);
}
