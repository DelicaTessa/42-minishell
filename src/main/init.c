/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:07 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/11 00:14:18 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <init.h>
#include <term_settings.h>
#include <envp_to_var.h>
#include <builtin_utils.h>
#include <envp_utils.h>

t_err	copy_to_ms_envp(char *str, t_ms_envp *custom_envp)
{
	char	*key;
	char	*value;

	if (!str)
		return (printf(RED "[copy_to_custom_envp] str to NULL..\n" RESET));
	if (get_env_key(str, &key) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ft_strlen(key) < ft_strlen(str))
	{
		if (str[ft_strlen(key)] != '=')
			return (printf(RED "[copy_to_custom_envp] no '=' sign..\n" RESET));
		value = ft_strdup(str + ft_strlen(key) + 1);
		if (!value)
		{
			free (key);
			return (MALLOC_FAIL);
		}
	}
	else
		value = NULL;
	custom_envp->key = key;
	custom_envp->value = value;
	return (NO_ERROR);
}

t_err	add_empty_oldpwd(t_ms_envp *ms_envp)
{
	ms_envp->key = ft_strdup("OLDPWD");
	if (!ms_envp->key)
		return (MALLOC_FAIL);
	return (NO_ERROR);
}

t_err	set_shlvl(t_envi *envi)
{
	int		lvl;
	char	*key;
	char	*value;

	if (get_env_value(envi->ms_envp, "SHLVL", &value) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (!value)
		lvl = 0;
	else
		lvl = ft_atoi(value);
	lvl++;
	if (lvl > 1)
		free(value);
	value = ft_itoa(lvl);
	if (!value)
		return (MALLOC_FAIL);
	if (key_exists("SHLVL", envi->ms_envp))
		return (replace_value("SHLVL", value, envi->ms_envp));
	key = ft_strdup("SHLVL");
	if (!key)
		return (MALLOC_FAIL);
	return (add_to_ms_envp(key, value, &envi->ms_envp));
}

t_err	init_var(char **envp, t_envi *envi)
{
	int	i;

	i = 0;
	ft_bzero(envi, sizeof(t_envi));
	while (envp[i])
		i++;
	envi->ms_envp = ft_calloc(i + 2, sizeof(t_ms_envp));
	if (!envi->ms_envp)
		return (MALLOC_FAIL);
	i = 0;
	while (envp[i])
	{
		copy_to_ms_envp(envp[i], &envi->ms_envp[i]);
		i++;
	}
	if (!key_exists("OLDPWD", envi->ms_envp))
		return (add_empty_oldpwd(&envi->ms_envp[i]));
	return (NO_ERROR);
}

t_err	ms_init(char **envp, t_envi *envi)
{
	if (init_var(envp, envi) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (ms_envp_to_var(envi->ms_envp, &envi->var) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (set_shlvl(envi) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	save_term_settings(&envi->termios_p);
	return (NO_ERROR);
}
