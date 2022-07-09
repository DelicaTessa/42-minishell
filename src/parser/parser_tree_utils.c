/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_tree_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 22:27:31 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:27:48 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <tree_utils.h>

t_tree	*next_tree(t_tree *tree)
{
	if (!tree)
	{
		printf(RED "[next_tree] Dead tree?!?!\n" RESET);
		return (NULL);
	}
	if (tree->left_node)
		tree = tree->left_node;
	else
		tree = next_root_node(tree);
	return (tree);
}

int	count_branches(t_token_list *list)
{
	int	counter;

	counter = 1;
	while (list)
	{
		if (list->type == TOK_PIPE)
			counter++;
		list = list->next;
	}
	printf(GRN "branch_count == %d\n" RESET, counter);
	return (counter);
}

t_token_list	*next_branch(t_token_list *list)
{
	if (!list)
		printf(RED "[next_branch] Empty t_token_list ?\n" RESET);
	while (list)
	{
		list = list->next;
		if (list && list->type == TOK_PIPE)
			return (list);
	}
	return (list);
}
