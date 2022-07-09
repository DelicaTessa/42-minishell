/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:32:35 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/07 23:47:00 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <builtins.h>

void	ft_exit_numeric(t_tree *tree, t_envi *envi, t_executor *exec)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(tree->data[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	envi->exitcode = 255;
	ft_exit_free(tree, exec, envi);
	exit(envi->exitcode);
}

int	ft_isplus(char *str)
{
	if (str[0] == '+')
		return (1);
	return (0);
}

int	ft_check_isalpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) || str[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_minus_plus(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] == '-')
			check++;
		if (str[i] == '+')
			check++;
		i++;
	}
	return (check);
}

int	ft_check_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
