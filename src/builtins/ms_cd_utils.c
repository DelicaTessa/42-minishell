/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_cd_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:12:24 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:47:59 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ms_cd_utils.h>

t_hard_strings	init_strings(void)
{
	t_hard_strings	strings;

	strings.oldpwd = ft_strdup("OLDPWD");
	if (strings.oldpwd)
		strings.pwd = ft_strdup("PWD");
	if (!strings.pwd)
	{
		free(strings.oldpwd);
		strings.oldpwd = NULL;
	}
	return (strings);
}

void	remove_dir(char parse_path[1024])
{
	int	i;

	i = 0;
	while (i < 255 && parse_path[i])
		i++;
	while (parse_path[i] != '/')
	{
		parse_path[i] = '\0';
		i--;
	}
	parse_path[i] = '\0';
}

int	add_slash(char parse_path[1024])
{
	int	i;

	i = 0;
	while (i < 1024 && parse_path[i])
		i++;
	parse_path[i] = '/';
	return (1);
}

int	add_path_chunk(char parse_path[1024], char *path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 1024 && parse_path[i])
		i++;
	if (i != 0 && parse_path[i - 1] != '/')
	{
		parse_path[i] = '/';
		i++;
	}
	while (path[j] && path[j] != '/')
	{
		parse_path[i] = path[j];
		i++;
		j++;
	}
	return (j);
}
