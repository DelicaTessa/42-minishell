/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_atoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 14:29:03 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/12 17:49:18 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>
#include <executor.h>

static long long	ft_skip(const char *str, long long i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	return (i);
}

long long	ft_atoi_exit(const char *str)
{
	long long	value;
	long long	i;
	long long	sign;

	i = ft_skip(str, 0);
	value = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (value * sign);
}

void	ft_exit_free(t_tree *tree, t_executor *exec, t_envi *envi)
{
	(void)tree;
	(void)exec;
	free_envi(envi);
}
