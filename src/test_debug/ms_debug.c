/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_debug.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:58 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 17:28:12 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <tree_utils.h>
#include <ms_debug_utils.h>

void	print_ms_envp(t_ms_envp *ms_envp)
{
	printf(YEL "\nMS_ENVP\n\n" RESET);
	while (ms_envp->key)
	{
		printf("%s=%s\n", ms_envp->key, ms_envp->value);
		ms_envp++;
	}
}

void	print_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("split[%d]: %s\n", i, split[i]);
		i++;
	}
	printf("\n");
}

void	print_tokens(t_token_list *token_list)
{
	while (token_list)
	{
		printf("\nTOK_ID   = %d\n", token_list->id);
		printf("TOK_TYPE = |%s|\n", get_token_str(token_list->type));
		printf("TOK_DATA = |%s|\n", token_list->data);
		token_list = token_list->next;
	}
	printf(YEL "\nEND OF LIST\n" RESET);
}

void	print_leave(t_tree *tree)
{
	printf("node_type(%d) = %s\n", tree->id, get_tree_str(tree->type));
	printf("data:\n");
	if (tree->data)
		print_split(tree->data);
}

void	print_full_tree(t_tree *tree)
{
	while (tree)
	{
		if (tree->type == PIPE || tree->type == NO_PIPE)
			printf(YEL "\n*** branch_node(%d) %s ***\n" RESET, \
				tree->id, get_tree_str(tree->type));
		else
			print_leave(tree);
		if (tree->left_node)
			tree = tree->left_node;
		else
			tree = next_root_node(tree);
	}
}
