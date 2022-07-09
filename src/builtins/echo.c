/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 12:27:40 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/07 23:36:36 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <datatypes.h>
#include <builtins.h>

int	ft_check_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i + 1] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_print_echo(t_tree *tree, int i, int err)
{
	int	j;

	while (tree->data[i])
	{
		j = ft_strlen(tree->data[i]);
		err = write(STDOUT_FILENO, tree->data[i], j);
		if (tree->data[i + 1] && err != -1)
			err = write(STDOUT_FILENO, " ", 1);
		if (err == -1)
			return (err);
		i++;
	}
	return (err);
}

int	ft_handle_echo(t_tree *tree, int i, int check, int err)
{
	int	ret;

	ret = 0;
	while (tree->data[i] && !(ft_strncmp(tree->data[i], "-n", 2)) && err == 0)
	{
		check++;
		ret = ft_check_n(tree->data[i]);
		if (ret)
			break ;
		i++;
	}
	err = ft_print_echo(tree, i, err);
	if (err == -1)
		return (err);
	if (!check)
		err = write(STDOUT_FILENO, "\n", 1);
	return (err);
}

int	ft_builtin_echo(t_envi *envi, t_tree *tree)
{
	int	i;
	int	check;
	int	err;

	i = 1;
	check = 0;
	err = 0;
	err = ft_handle_echo(tree, i, check, err);
	if (err == -1)
	{
		ft_putstr_fd("minishell: error in echo.\n", 2);
		envi->exitcode = 1;
	}
	else
		envi->exitcode = 0;
	return (1);
}
