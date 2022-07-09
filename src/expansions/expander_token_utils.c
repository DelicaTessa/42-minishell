/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_token_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:14:48 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:45:29 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <token_utils.h>

t_err	join_head_token(t_token_list **list, t_token_type resulting_type)
{
	t_token_list	*new_token;
	char			*new_data;

	new_data = ft_strjoin((*list)->data, (*list)->next->data);
	if (!new_data)
		return (MALLOC_FAIL);
	new_token = create_token(resulting_type, new_data);
	if (!new_token)
	{
		free (new_data);
		return (MALLOC_FAIL);
	}
	new_token->next = (*list)->next->next;
	if ((*list)->next->next)
		(*list)->next->next->prev = new_token;
	del_token((*list)->next);
	del_token(*list);
	*list = new_token;
	return (NO_ERROR);
}

t_err	join_token(t_token_list *list, t_token_type resulting_type)
{
	t_token_list	*new_token;
	char			*new_data;

	new_data = ft_strjoin(list->data, list->next->data);
	if (!new_data)
		return (MALLOC_FAIL);
	new_token = create_token(resulting_type, new_data);
	if (!new_token)
	{
		free (new_data);
		return (MALLOC_FAIL);
	}
	new_token->next = list->next->next;
	if (new_token->next)
		list->next->next->prev = new_token;
	new_token->prev = list->prev;
	list->prev->next = new_token;
	del_token(list->next);
	del_token(list);
	return (NO_ERROR);
}

void	cut_head_token(t_token_list **head)
{
	t_token_list	*new_head;

	if (!*head)
		return ((void)printf(RED "[cut_head_token] empty list.\n" RESET));
	if ((*head)->prev)
		return ((void)printf(RED "[cut_head_token] this is no head..\n" RESET));
	else if ((*head)->next)
	{
		new_head = (*head)->next;
		new_head->prev = NULL;
		del_token(*head);
		*head = new_head;
	}
	else
	{
		del_token(*head);
		*head = NULL;
	}
}

void	cut_token(t_token_list *list)
{
	if (!list)
		return ((void)printf(RED "[cut_token] no token_list..\n" RESET));
	if (!list->prev)
		return ((void)printf(RED "[cut_token] no prev in token_list..\n" RESET));
	if (list->next)
		list->next->prev = list->prev;
	list->prev->next = list->next;
	del_token(list);
}
