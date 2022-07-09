/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dirs.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 15:34:58 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/25 15:08:35 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	ft_cmd_exit(char **arg, t_envi *envi, char **paths)
{
	(void)paths;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_envi(envi);
	exit(127);
}

void	ft_dir_exit(char **arg, t_envi *envi, char **paths)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg[0], 2);
	ft_putstr_fd(": is a directory\n", 2);
	free_envi(envi);
	ft_free_paths(paths, NULL, NULL);
	exit(126);
}

int	ft_parse_dir_loop(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_dir(char **envp, char **arg, t_envi *envi, char **paths)
{
	struct stat	f;
	int			flag;

	if (lstat(arg[0], &f) != -1)
	{
		flag = f.st_mode & S_IFMT;
		if (flag == S_IFDIR)
			ft_dir_exit(arg, envi, paths);
		else if (flag == S_IFREG)
		{
			ft_check_access(arg[0], envp, arg, envi);
			ft_exec_cmd(arg[0], envp, arg, envi);
		}
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg[0], 2);
	ft_putstr_fd(": no such file or directory\n", 2);
	ft_free_paths(paths, NULL, NULL);
	free_envi(envi);
	exit(127);
	return (0);
}

int	ft_parse_dir(char **envp, char **arg, t_envi *envi, char **paths)
{
	if (!ft_strncmp(arg[0], ".", 2))
	{
		ft_putstr_fd("minishell: .: filename argument required\n", 2);
		ft_putstr_fd(".: usage: . filename [arguments]\n", 2);
		free_envi(envi);
		ft_free_paths(paths, NULL, NULL);
		exit(2);
	}
	if ((!ft_strncmp(arg[0], "/", 1)) || (!ft_strncmp(arg[0], "./", 2))
		|| (!ft_strncmp(arg[0], "../", 3)))
		if (ft_parse_dir_loop(arg[0]))
			ft_dir_exit(arg, envi, paths);
	if ((!ft_strncmp(arg[0], "/", 1)) || (!ft_strncmp(arg[0], "./", 2))
		|| (!ft_strncmp(arg[0], "../", 3)))
		ft_is_dir(envp, arg, envi, paths);
	if (!ft_strncmp(arg[0], "..", 3))
	{
		ft_free_paths(paths, NULL, NULL);
		ft_cmd_exit(arg, envi, NULL);
	}
	return (0);
}
