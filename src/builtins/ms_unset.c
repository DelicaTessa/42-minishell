/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_unset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:33:53 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:46:46 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <envp_to_var.h>
#include <lexer_utils.h>

void	copy_or_rm(t_ms_envp **envp, char *key, t_ms_envp **new_envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*envp)[i].key)
	{
		if (ft_strncmp((*envp)[i].key, key, ft_strlen(key) + 1))
		{
			(*new_envp)[j].key = (*envp)[i].key;
			(*new_envp)[j].value = (*envp)[i].value;
			j++;
		}
		else
		{
			free((*envp)[i].key);
			free((*envp)[i].value);
		}
		i++;
	}
}

t_err	rm_from_envp(char *key, t_ms_envp **envp)
{
	t_ms_envp	*new_envp;
	int			i;

	i = 0;
	while ((*envp)[i].key)
		i++;
	new_envp = ft_calloc(i + 1, sizeof(t_ms_envp));
	if (!new_envp)
		return (MALLOC_FAIL);
	copy_or_rm(envp, key, &new_envp);
	free(*envp);
	*envp = new_envp;
	return (NO_ERROR);
}

int	is_unset_key(char *key)
{
	size_t	i;

	i = 0;
	if (!key)
		return (0);
	if (ft_isdigit(key[0]) || key[0] == '-')
		return (0);
	while (key[i] && char_is_allowed(key[i], "/\\;.+=-{}*#@!^~"))
		i++;
	if (ft_strlen(key) == i)
		return (1);
	return (0);
}

int	unset_error_msg(char *str)
{
	if (str[0] == '-' && str[1] != '\0')
	{
		ft_putstr_fd("minishell: unset: -", 2);
		ft_putchar_fd(str[1], 2);
		ft_putstr_fd(": invalid option\n", 2);
		ft_putstr_fd("unset: usage: unset [name ...]\n", 2);
		return (2);
	}
	ft_putstr_fd("minishell: unset: '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

int	ms_unset(char **argv, t_envi *envi)
{
	int	i;
	int	exitcode;

	if (!argv)
		return (printf(RED "[ms_unset] NULL-pointing argv..\n" RESET));
	if (!argv[1])
		return (0);
	exitcode = 0;
	i = 1;
	while (argv[i])
	{
		if (!ft_strncmp(argv[i], "PWD", 4))
			return (0);
		else if (!is_unset_key(argv[i]))
			exitcode = unset_error_msg(argv[i]);
		else
			rm_from_envp(argv[i], &envi->ms_envp);
		i++;
	}
	if (ms_envp_to_var(envi->ms_envp, &envi->var) == MALLOC_FAIL)
		return (-1);
	return (exitcode);
}
