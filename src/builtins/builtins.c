/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 14:09:22 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/25 15:06:45 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <executor.h>
#include <builtins.h>
#include <ms_export.h>
#include <ms_env.h>
#include <ms_unset.h>
#include <ms_cd.h>

void	ft_check_export(t_tree *tree, t_envi *envi)
{
	int	exit_code;

	if (!ft_strncmp(tree->data[0], "export", 7) && tree->data[1])
	{
		free_envi(envi);
		exit(0);
	}
	else if (!ft_strncmp(tree->data[0], "export", 7))
	{
		exit_code = ms_export(tree->data, envi);
		free_envi(envi);
		exit(exit_code);
	}
}

int	ft_check_builtin_end(t_tree *tree, t_envi *envi, int i)
{
	if (!ft_strncmp(tree->data[0], "env", 4))
	{
		envi->exitcode = ms_env(tree->data, envi);
		i++;
	}
	if (i != 0)
	{
		free_envi(envi);
		exit(envi->exitcode);
	}
	return (i);
}

int	ft_check_builtin(t_tree *tree, t_envi *envi)
{
	int	i;

	i = 0;
	if (!ft_strncmp(tree->data[0], "echo", 5))
		i = ft_builtin_echo(envi, tree);
	else if (!ft_strncmp(tree->data[0], "cd", 3) || \
		!ft_strncmp(tree->data[0], "exit", 5))
	{
		free_envi(envi);
		exit(0);
	}
	else if (!ft_strncmp(tree->data[0], "pwd", 4))
		i = ft_pwd_builtin(envi);
	ft_check_export(tree, envi);
	if (!ft_strncmp(tree->data[0], "unset", 6))
		i = 33;
	i = ft_check_builtin_end(tree, envi, i);
	return (i);
}

int	ft_check_builtin_add(t_tree *tree, t_envi *envi, int i)
{
	if (!ft_strncmp(tree->data[0], "pwd", 4))
		i = ft_pwd_builtin(envi);
	else if (!ft_strncmp(tree->data[0], "export", 6))
	{
		envi->exitcode = ms_export(tree->data, envi);
		i++;
	}
	else if (!ft_strncmp(tree->data[0], "unset", 6))
	{
		envi->exitcode = ms_unset(tree->data, envi);
		i++;
	}
	else if (!ft_strncmp(tree->data[0], "env", 4))
	{
		envi->exitcode = ms_env(tree->data, envi);
		i++;
	}
	return (i);
}

int	ft_check_builtin_child(t_tree *tree, t_envi *envi, t_executor *exec)
{
	int	i;

	i = 0;
	if (!ft_strncmp(tree->data[0], "echo", 4))
		i = ft_builtin_echo(envi, tree);
	else if (!ft_strncmp(tree->data[0], "cd", 3))
	{
		envi->exitcode = ms_cd(tree->data, envi);
		i++;
	}
	i = ft_check_builtin_add(tree, envi, i);
	if (!ft_strncmp(tree->data[0], "exit", 5))
	{
		envi->exitcode = ft_exit(tree, envi, exec);
		i++;
	}
	if (i != 0)
	{
		free_envi(envi);
		exit(envi->exitcode);
	}
	else
		return (i);
}
