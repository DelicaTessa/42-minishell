/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_loop_builtin.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/10 10:05:59 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/21 14:11:16 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <datatypes.h>
#include <executor.h>
#include <ms_export.h>
#include <ms_unset.h>
#include <builtins.h>
#include <ms_cd.h>

int	ft_check_nonwriteable(t_tree *tree, t_envi *envi, t_executor *exec)
{
	exec->builtin_check = 0;
	while (tree)
	{
		if (tree->type == CMD)
		{
			if (!tree->data[0])
				break ;
			ft_start_builtin(tree, envi, exec);
			break ;
		}
		tree = get_next_node(tree);
	}
	return (0);
}

int	ft_start_builtin(t_tree *tree, t_envi *envi, t_executor *exec)
{
	if (!ft_strncmp(tree->data[0], "export", 7) && tree->data[1])
	{
		envi->exitcode = ms_export(tree->data, envi);
		exec->builtin_check = 1;
	}
	else if (!ft_strncmp(tree->data[0], "cd", 3))
	{
		envi->exitcode = ms_cd(tree->data, envi);
		exec->builtin_check = 1;
	}
	else if (!ft_strncmp(tree->data[0], "unset", 6))
	{
		envi->exitcode = ms_unset(tree->data, envi);
		exec->builtin_check = 1;
	}
	else if (!ft_strncmp(tree->data[0], "exit", 5))
	{
		envi->exitcode = ft_exit(tree, envi, exec);
		exec->builtin_check = 1;
	}
	return (0);
}
