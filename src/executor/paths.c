/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 13:15:12 by tclement      #+#    #+#                 */
/*   Updated: 2022/05/01 17:49:42 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	*ft_free_paths(char **first, char **second, char *third)
{
	int	i;

	i = 0;
	if (first[i])
	{
		while (first[i])
		{
			free(first[i]);
			i++;
		}
	}
	free (first);
	first = NULL;
	if (third)
		free (third);
	if (second)
		ft_free_paths(second, NULL, NULL);
	return (NULL);
}

char	**ft_edit_paths(char **paths, char **arg, int i)
{
	char	**exec_paths;
	char	*extension;
	int		j;

	exec_paths = (char **)malloc(sizeof(char *) * (i + 1));
	if (!exec_paths)
		return (ft_free_paths(paths, NULL, NULL));
	j = 0;
	extension = ft_strjoin("/", arg[0]);
	if (!extension)
		return (ft_free_paths(paths, exec_paths, NULL));
	while (paths[j])
	{
		exec_paths[j] = ft_strjoin(paths[j], extension);
		if (!exec_paths[j])
			return (ft_free_paths(paths, exec_paths, extension));
		j++;
	}
	exec_paths[j] = NULL;
	ft_free_paths(paths, NULL, extension);
	return (exec_paths);
}

char	*get_path_env(char *temp)
{
	char	*path;

	path = ft_strtrim(temp, "PATH=");
	free (temp);
	if (!path)
		return (NULL);
	return (path);
}

char	*find_path_env(char **envp, t_envi *envi)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	while (envp[i] != NULL)
	{
		if (!(ft_strncmp(envp[i], "PATH", 4)))
		{
			len = ft_strlen(envp[i]);
			temp = (char *)malloc(sizeof(char) * (len + 1));
			if (!temp)
				ft_error_exec(5, 0, envi);
			temp = ft_memcpy(temp, envp[i], ft_strlen(envp[i]));
			temp[len] = '\0';
			return (get_path_env(temp));
		}
		i++;
	}
	return (NULL);
}

int	ft_get_paths(t_envi *envi, char **arg)
{
	char	*path;
	char	**paths;

	paths = NULL;
	path = find_path_env(envi->var, envi);
	if (path)
	{
		paths = ft_split(path, ':');
		free (path);
	}
	else
		paths = ft_split("", ' ');
	if (!paths)
		ft_error_exec(5, 0, envi);
	ft_acces_and_exec(envi, arg, paths);
	return (0);
}
