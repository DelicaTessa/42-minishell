/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:39:06 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:37:11 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <datatypes.h>
#include <tree_utils.h>

t_tree	*create_tree_node(t_nodetype type, char **data)
{
	static int	branch_id = 0;
	static int	leave_id = 0;
	t_tree		*new_tree;

	new_tree = ft_calloc(sizeof(t_tree), 1);
	if (!new_tree)
		return (NULL);
	new_tree->type = type;
	new_tree->data = data;
	if (type == NO_PIPE || type == PIPE)
	{
		new_tree->id = branch_id;
		branch_id++;
		leave_id = 0;
		if (type == NO_PIPE)
			branch_id = 0;
	}
	else
	{
		new_tree->id = leave_id;
		leave_id++;
	}
	return (new_tree);
}

t_err	add_root_node(t_nodetype type, t_tree **head_tree)
{
	t_tree	*node;
	t_tree	*new_node;

	node = *head_tree;
	new_node = create_tree_node(type, NULL);
	if (!new_node)
		return (MALLOC_FAIL);
	if (!*head_tree)
	{
		*head_tree = new_node;
		return (NO_ERROR);
	}
	node = last_root_node(node);
	new_node->prev_node = node;
	node->right_node = new_node;
	return (NO_ERROR);
}

t_err	add_leaf_node(t_nodetype type, char **data, t_tree *parent)
{
	t_tree	*new_node;

	if (!parent)
		return (printf(RED "[add_child_node] No parent tree!?!?!\n" RESET));
	new_node = create_tree_node(type, data);
	if (!new_node)
		return (MALLOC_FAIL);
	while (parent->right_node)
		parent = parent->right_node;
	if (parent->left_node == NULL)
		parent->left_node = new_node;
	else
	{
		while (parent->left_node)
			parent = parent->left_node;
		parent->left_node = new_node;
	}
	new_node->prev_node = parent;
	return (NO_ERROR);
}

t_err	add_tree_node(t_nodetype type, t_tree **tree, char **data)
{	
	if (type == PIPE || type == NO_PIPE)
	{
		if (!data)
			add_root_node(type, tree);
		else
			printf(RED "PIPE/NO_PIPE node should not have data!!\n" RESET);
	}
	else
		add_leaf_node(type, data, *tree);
	return (NO_ERROR);
}
