/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:11:25 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/13 09:43:27 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

int	ft_exec_cmd(char *path, char **envp, char **arg, t_envi *envi)
{
	if (execve(path, arg, envp) < 0)
		ft_error_exec(4, 0, envi);
	return (0);
}

int	ft_check_access(char *path, char **envp, char **arg, t_envi *envi)
{
	int	check;

	check = access(path, X_OK);
	if (check != 0 && arg && envp)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(arg[0], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		free_envi(envi);
		exit(126);
	}
	return (check);
}

char	*ft_search_bins(char **exec_paths)
{
	struct stat	stat;
	int			i;

	i = 0;
	while (exec_paths && exec_paths[i])
	{
		if (!(lstat(exec_paths[i], &stat)))
			return (exec_paths[i]);
		i++;
	}
	return (NULL);
}

int	ft_acces_and_exec(t_envi *envi, char **arg, char **paths)
{
	char	**exec_paths;
	char	*path;
	int		i;

	i = 0;
	exec_paths = NULL;
	ft_parse_dir(envi->var, arg, envi, paths);
	while (paths && paths[i])
		i++;
	if (paths)
		exec_paths = ft_edit_paths(paths, arg, i);
	if (!exec_paths)
		ft_error_exec(5, 0, envi);
	path = ft_search_bins(exec_paths);
	if (path)
	{
		i = ft_check_access(path, envi->var, arg, envi);
		ft_exec_cmd(path, envi->var, arg, envi);
	}
	ft_free_paths(exec_paths, NULL, NULL);
	if (!path)
		ft_cmd_exit(arg, envi, paths);
	return (0);
}
