/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_loop_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 11:40:17 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/28 18:10:33 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <unistd.h>
#include <termios.h>
#include <ms_signals.h>

void	ft_nopipe_child(t_tree *tree, t_envi *envi, t_executor *exec)
{
	while (tree->left_node)
	{
		ft_redirs_loop(tree, exec, envi);
		tree = get_next_node(tree);
	}
	if (tree->type == CMD)
		ft_helper_nopipe_end(tree, envi, exec);
}

int	ft_nopipe_end(t_tree *tree, t_envi *envi, t_executor *exec)
{
	pid_t	pid;
	int		status;

	status = 0;
	exec->index++;
	exec->fd_in[0] = exec->fd_out[0];
	exec->fd_in[1] = exec->fd_out[1];
	if (prev_heredoc_exists(tree) == 1)
		wait(&status);
	pid = fork();
	if (pid < 0)
		ft_error_exec(1, 0, envi);
	if (!pid)
		ft_nopipe_child(tree, envi, exec);
	if (ft_nopipe_end_util(tree, pid, status) == 33)
		return (33);
	ft_close_fd(exec->fd_in);
	return (0);
}

int	ft_pipe_inbetween(t_envi *envi, t_tree *tree, t_executor *exec)
{
	pid_t	pid;
	int		status;

	exec->index++;
	if (pipe(exec->fd_out) < 0)
		ft_error_exec(3, 0, envi);
	if (prev_heredoc_exists(tree) == 1)
		wait(&status);
	pid = fork();
	if (pid < 0)
		ft_error_exec(1, exec->fd_out, envi);
	if (!pid)
		ft_helper_pipe_inbetween(tree, envi, exec);
	if (tree->left_node && tree->left_node->type == HERE_DOC)
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) == 1)
			return (33);
	}
	ft_close_fd(exec->fd_in);
	return (0);
}

int	ft_nopipe_start(t_envi *envi, t_tree *tree, t_executor *exec)
{
	pid_t	pid;

	exec->index++;
	pid = fork();
	if (pid < 0)
		ft_error_exec(1, 0, envi);
	if (!pid)
	{
		restore_signals();
		while (tree->left_node)
		{
			ft_redirs_loop(tree, exec, envi);
			tree = get_next_node(tree);
		}
		if (tree->type == CMD)
			ft_helper_nopipe_start(tree, envi);
	}
	ft_check_nonwriteable(tree, envi, exec);
	return (0);
}

int	ft_pipe_start(t_envi *envi, t_tree *tree, t_executor *exec)
{
	pid_t	pid;
	int		i;

	exec->index++;
	if (pipe(exec->fd_out) < 0)
		ft_error_exec(3, exec->fd_out, envi);
	pid = fork();
	if (pid < 0)
		ft_error_exec(1, 0, envi);
	if (!pid)
	{
		restore_signals();
		ft_helper_pipe_start(tree, envi, exec);
	}
	i = ft_pipe_start_util(tree, pid);
	if (i == 34)
		return (34);
	return (0);
}
