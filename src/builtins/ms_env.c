/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:00:43 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/05/01 21:19:33 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <executor.h>

int	env_error_msg( t_envi *envi)
{
	(void)envi;
	ft_putstr_fd("minishell: env", 2);
	ft_putstr_fd(": argument(s) unsupported\n", 2);
	ft_putstr_fd("env: usage: env\n", 2);
	exit (1);
}

int	ms_env(char **argv, t_envi *envi)
{
	t_ms_envp	*ms_envp;

	if (argv[1])
	{
		free_envi(envi);
		env_error_msg(envi);
	}
	ms_envp = envi->ms_envp;
	while (ms_envp->key)
	{
		if (ms_envp->value)
			printf("%s=%s\n", ms_envp->key, ms_envp->value);
		ms_envp++;
	}
	return (0);
}
