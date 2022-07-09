/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_loop_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 10:37:41 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/25 15:03:38 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	ft_helper_nopipe_end(t_tree *tree, t_envi *envi, t_executor *exec)
{
	if (!tree->data[0] || !ft_strncmp(tree->data[0], "", 1))
	{
		ft_close_fd(exec->fd_in);
		ft_close_fd(exec->fd_out);
		free_envi(envi);
		exit(0);
	}
	dup2(exec->fd_in[0], STDIN_FILENO);
	ft_close_fd(exec->fd_in);
	ft_close_fd(exec->fd_out);
	ft_check_builtin_child(tree, envi, exec);
	ft_get_paths(envi, tree->data);
}

void	ft_helper_pipe_inbetween(t_tree *tree, t_envi *envi, t_executor *exec)
{
	while (tree->left_node)
	{
		ft_redirs_loop(tree, exec, envi);
		tree = get_next_node(tree);
	}
	if (tree->type == CMD)
	{
		if (!tree->data[0] || !ft_strncmp(tree->data[0], "", 1))
		{
			ft_close_fd(exec->fd_in);
			ft_close_fd(exec->fd_out);
			free_envi(envi);
			exit(0);
		}
		if (exec->fd_in[0])
			dup2(exec->fd_in[0], STDIN_FILENO);
		dup2(exec->fd_out[1], STDOUT_FILENO);
		ft_close_fd(exec->fd_in);
		ft_close_fd(exec->fd_out);
		ft_check_builtin_child(tree, envi, exec);
		ft_get_paths(envi, tree->data);
	}
}

void	ft_helper_pipe_start(t_tree *tree, t_envi *envi, t_executor *exec)
{
	while (tree->left_node)
	{
		ft_redirs_loop(tree, exec, envi);
		tree = get_next_node(tree);
	}
	if (tree->type == CMD)
	{
		if (!tree->data[0] || !ft_strncmp(tree->data[0], "", 1))
		{
			ft_close_fd(exec->fd_in);
			ft_close_fd(exec->fd_out);
			free_envi(envi);
			exit(0);
		}
		dup2(exec->fd_out[1], STDOUT_FILENO);
		ft_close_fd(exec->fd_out);
		ft_check_builtin_child(tree, envi, exec);
		ft_get_paths(envi, tree->data);
	}
	else
	{
		ft_close_fd(exec->fd_in);
		ft_close_fd(exec->fd_out);
	}
}

void	ft_helper_nopipe_start(t_tree *tree, t_envi *envi)
{
	if (!tree->data[0] || !ft_strncmp(tree->data[0], "", 1))
	{
		free_envi(envi);
		exit(0);
	}
	ft_check_builtin(tree, envi);
	ft_get_paths(envi, tree->data);
}

int	prev_heredoc_exists(t_tree *tree)
{
	if (!tree)
		return (0);
	tree = tree->prev_node;
	while (tree && tree->type != HERE_DOC)
		tree = tree->left_node;
	if (!tree)
		return (0);
	return (1);
}
