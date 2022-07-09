/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:39:09 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:48:37 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>

static void	clean_leaves(t_tree *root_tree)
{
	t_tree	*next_leave;

	while (root_tree)
	{
		next_leave = root_tree->left_node;
		ft_free_split(&root_tree->data);
		free (root_tree);
		root_tree = next_leave;
	}
}

void	clean_tree(t_tree **head_tree)
{
	t_tree	*node;
	t_tree	*next_root;

	node = *head_tree;
	if (!node)
		return ;
	while (node)
	{
		next_root = node->right_node;
		clean_leaves(node);
		node = next_root;
	}
	*head_tree = NULL;
}

t_tree	*next_root_node(t_tree *tree)
{
	if (tree->type == PIPE || tree->type == NO_PIPE)
		return (tree->right_node);
	while (tree->prev_node && tree->type != PIPE && tree->type != NO_PIPE)
		tree = tree->prev_node;
	return (tree->right_node);
}

t_tree	*get_next_node(t_tree *tree)
{
	if (!tree)
	{
		printf(RED "Empty forrest?!?!?\n");
		return (NULL);
	}
	if (tree->left_node)
		tree = tree->left_node;
	else
		tree = next_root_node(tree);
	return (tree);
}

t_tree	*last_root_node(t_tree *tree)
{
	if (tree->type == PIPE || tree->type == NO_PIPE)
	{
		while (tree->right_node)
			tree = tree->right_node;
		return (tree);
	}
	while (tree->left_node)
		tree = tree->left_node;
	return (last_root_node(tree));
}
