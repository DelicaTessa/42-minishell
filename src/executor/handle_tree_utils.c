/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_tree_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/04 14:18:10 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/28 18:10:00 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

int	ft_handle_loop(t_envi *envi, t_executor *exec, t_tree *tree)
{
	int	i;

	i = 0;
	if (tree->type == NO_PIPE && exec->index > 0)
	{
		i = ft_nopipe_end(tree, envi, exec);
		if (i == 33)
		{
			ft_handle_heredoc(exec, envi);
			return (i);
		}
	}
	if (tree->type == PIPE && exec->index > 0)
	{
		i = ft_pipe_inbetween(envi, tree, exec);
		if (i == 33)
		{
			ft_handle_heredoc(exec, envi);
			return (i);
		}
		if (i == 666)
			return (i);
	}
	return (0);
}

int	ft_handle_loop_two(t_envi *envi, t_executor *exec, t_tree *tree)
{
	int	i;

	i = 0;
	if (tree->type == PIPE && exec->index == 0)
	{
		i = ft_pipe_start(envi, tree, exec);
		if (i == 33)
		{
			ft_handle_heredoc(exec, envi);
			return (i);
		}
		if (i == 34)
			return (i);
	}
	return (0);
}

void	ft_close_all(t_executor *exec)
{
	ft_close_fd(exec->fd_out);
	ft_close_fd(exec->fd_in);
}

int	ft_pipe_start_util(t_tree *tree, pid_t pid)
{
	int	status;

	status = 0;
	if (tree->left_node && tree->left_node->type == HERE_DOC)
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) != 81)
			return (34);
	}
	return (0);
}
