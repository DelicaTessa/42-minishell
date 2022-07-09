/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:34 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:44:33 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>

void	del_token(t_token_list *list)
{
	if (!list)
	{
		printf(RED "[del_token] (Null) token!!\n" RESET);
		return ;
	}
	ft_free_str(&list->data);
	free (list);
}

t_token_list	*create_token(t_token_type type, char *data)
{
	static int		id = 0;
	t_token_list	*new_token;

	new_token = ft_calloc(sizeof(t_token_list), 1);
	if (new_token)
	{
		new_token->type = type;
		new_token->data = data;
		new_token->id = id;
		id++;
	}
	return (new_token);
}

void	add_to_tokenlist(t_token_list **head, t_token_list *new)
{
	t_token_list	*node;

	if (!*head)
		*head = new;
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		new->prev = node;
		node->next = new;
	}
}

t_err	add_new_token_to_list(t_token_list **head, \
		t_token_type type, char *data)
{
	t_token_list	*new;

	new = create_token(type, data);
	if (!new)
		return (MALLOC_FAIL);
	add_to_tokenlist(head, new);
	return (NO_ERROR);
}
