/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/24 13:47:58 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/08 14:15:49 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

int	ft_error_exec(int code, int *fd, t_envi *envi)
{
	if (fd != 0)
		close(*fd);
	free_envi(envi);
	ft_putstr_fd("minishell: ", 2);
	if (code == 1)
		ft_putstr_fd("fork error\n", 2);
	else if (code == 3)
		ft_putstr_fd("pipe error\n", 2);
	if (code >= 1 && code <= 3)
		exit(71);
	if (code == 4)
	{
		ft_putstr_fd("execve error\n", 2);
		exit(126);
	}
	else if (code == 5)
		ft_putstr_fd("malloc error\n", 2);
	else if (code == 6)
		ft_putstr_fd("acces error\n", 2);
	exit(1);
	return (-1);
}

int	ft_redir_error(t_tree *tree, int fd, t_envi *envi)
{
	close(fd);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(tree->data[0], 2);
	ft_putstr_fd(": Permission denied\n", 2);
	free_envi(envi);
	exit(1);
	return (-1);
}

int	ft_redir_in_error(t_tree *tree, t_envi *envi)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(tree->data[0], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	free_envi(envi);
	exit(1);
	return (-1);
}
