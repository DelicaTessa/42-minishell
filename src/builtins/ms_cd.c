/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 14:55:23 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:47:41 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <datatypes.h>
#include <ms_cd_utils.h>
#include <envp_utils.h>
#include <envp_to_var.h>
#include <builtin_utils.h>
#include <ms_errors.h>

t_err	update_both_pwds(t_envi *envi, char *curr_pwd, char *new_pwd)
{
	t_hard_strings	strings;

	strings = init_strings();
	if (!strings.pwd)
		return (MALLOC_FAIL);
	if (key_exists("PWD", envi->ms_envp))
	{
		replace_value(strings.pwd, new_pwd, envi->ms_envp);
		free(strings.pwd);
	}
	else
	{
		if (add_to_ms_envp(strings.pwd, new_pwd, &envi->ms_envp) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	if (key_exists("OLDPWD", envi->ms_envp))
	{
		replace_value(strings.oldpwd, curr_pwd, envi->ms_envp);
		free(strings.oldpwd);
		return (NO_ERROR);
	}
	else if (add_to_ms_envp(strings.oldpwd, curr_pwd, &envi->ms_envp) == 1)
		return (MALLOC_FAIL);
	return (NO_ERROR);
}

char	*parse_path(char *path, char *old_pwd)
{
	int			i;
	char		parse_path[512];

	ft_bzero(&parse_path, 512);
	ft_strlcpy(parse_path, old_pwd, ft_strlen(old_pwd) + 1);
	i = 0;
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == '.')
		{
			remove_dir(parse_path);
			i += 2;
		}
		else if (path[i] == '.' && path[i + 1] == '/')
			i += 2;
		else if (path[i] == '/')
			i++;
		else if (ft_isprint(path[i]))
			i += add_path_chunk(parse_path, &path[i]);
		else
			printf(RED "[parse_path] something rly wrong..." RESET);
	}
	return (ft_strdup(parse_path));
}

t_err	only_update_oldpwd(t_envi *envi, char *curr_pwd)
{
	char	*key;

	key = NULL;
	if (key_exists("OLDPWD", envi->ms_envp))
		return ((t_err)replace_value("OLDPWD", curr_pwd, envi->ms_envp));
	key = ft_strdup("OLDPWD");
	if (!key)
		return (MALLOC_FAIL);
	return (add_to_ms_envp(key, curr_pwd, &envi->ms_envp));
}

t_err	update_pwd_oldpwd(char *path, t_envi *envi)
{
	char	*new_pwd;
	char	*curr_pwd;

	if (get_env_value(envi->ms_envp, "PWD", &curr_pwd) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (!ft_strncmp(path, ".", 2))
		return (only_update_oldpwd(envi, curr_pwd));
	if (path[0] == '/')
		new_pwd = ft_strdup(path);
	else
		new_pwd = parse_path(path, curr_pwd);
	if (!new_pwd)
	{
		free(curr_pwd);
		return (MALLOC_FAIL);
	}
	update_both_pwds(envi, curr_pwd, new_pwd);
	return (NO_ERROR);
}

t_err	ms_cd(char **argv, t_envi *envi)
{
	if (!argv)
		return (printf(RED "[ms_cd] NULL-pointing argv..\n" RESET));
	if (!*argv)
		return (printf(RED "[ms_cd] empty argv..\n" RESET));
	if (!argv[1])
		return (0);
	if (chdir(argv[1]))
		return (ms_perror("Minishell: cd", argv[1], NULL, 1));
	if (update_pwd_oldpwd(argv[1], envi) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ms_envp_to_var(envi->ms_envp, &envi->var) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	return (NO_ERROR);
}
