/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:12:13 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/30 15:59:55 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	ft_exit_multi_arg(t_tree *tree, t_envi *envi, int i, t_executor *exec)
{
	int	check;

	check = 0;
	if (!ft_strncmp(tree->data[0], "exit", 5) && i > 2)
	{
		check = ft_check_minus_plus(tree->data[1]);
		if (ft_check_isalpha(tree->data[1]) || check > 1)
			ft_exit_numeric(tree, envi, exec);
		else
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			envi->exitcode = 1;
		}
	}
}

void	ft_exit_one_arg_plus(t_tree *tree, t_envi *envi, t_executor *exec)
{
	envi->exitcode = (ft_atoi_exit(tree->data[1]) % 256);
	ft_putstr_fd("exit\n", 2);
	ft_exit_free(tree, exec, envi);
	exit(envi->exitcode);
}

void	ft_exit_one_range(t_tree *tree, t_envi *envi, t_executor *exec)
{
	unsigned long long	range;

	range = ft_atoi_exit(tree->data[1]);
	if (!(ft_strcmp(tree->data[1], "9223372036854775807")))
		ft_exit_one_arg_plus(tree, envi, exec);
	else if (range > 9223372036854775806)
		ft_exit_numeric(tree, envi, exec);
}

void	ft_exit_one_arg(t_tree *tree, t_envi *envi, int i, t_executor *exec)
{
	int	check;

	check = 0;
	if (!ft_strncmp(tree->data[0], "exit", 5) && i == 2)
	{
		check = ft_check_minus_plus(tree->data[1]);
		if (ft_check_isalpha(tree->data[1]) || check > 1)
			ft_exit_numeric(tree, envi, exec);
		else if (!ft_check_isdigit(tree->data[1]) && check == 1)
			ft_exit_numeric(tree, envi, exec);
		ft_exit_one_range(tree, envi, exec);
		if (check == 1 && !ft_isplus(tree->data[1]))
		{
			check = (ft_atoi_exit(tree->data[1]) % 256);
			envi->exitcode = 256 - check;
			ft_putstr_fd("exit\n", 2);
			ft_exit_free(tree, exec, envi);
			exit(envi->exitcode);
		}
		else if (check == 0 || ft_isplus(tree->data[1]))
			ft_exit_one_arg_plus(tree, envi, exec);
	}
}

int	ft_exit(t_tree *tree, t_envi *envi, t_executor *exec)
{
	int	i;

	i = 0;
	while (tree->data[i])
		i++;
	if (!ft_strncmp(tree->data[0], "exit", 5) && i == 1)
	{
		ft_putstr_fd("exit\n", 2);
		envi->exitcode = 0;
		ft_exit_free(tree, exec, envi);
		exit(envi->exitcode);
	}
	ft_exit_multi_arg(tree, envi, i, exec);
	ft_exit_one_arg(tree, envi, i, exec);
	return (envi->exitcode);
}
