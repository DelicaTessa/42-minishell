/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_envp_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:05:28 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:42:08 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>

char	*point_to_value(char *str)
{
	str = ft_strchr(str, '=');
	if (str)
		str++;
	return (str);
}

t_bool	key_exists(char *key, t_ms_envp *ms_envp)
{
	int	key_len;

	if (!ms_envp)
		return (printf(RED "[key_exists] ms_envp pointing to NULL?!\n" RESET));
	key_len = ft_strlen(key);
	while (ms_envp->key)
	{
		if (ft_strncmp(ms_envp->key, key, key_len + 1) == 0)
			return (TRUE);
		ms_envp++;
	}
	return (FALSE);
}

t_err	replace_value(char *key, char *value, t_ms_envp *envp)
{
	int	i;

	i = 0;
	while (envp[i].key)
	{
		if (ft_strncmp(envp[i].key, key, ft_strlen(key) + 1) == 0)
		{
			if (envp[i].value)
				free(envp[i].value);
			envp[i].value = value;
			break ;
		}
		i++;
	}
	return (NO_ERROR);
}

t_err	add_to_ms_envp(char *key, char *value, t_ms_envp **head)
{
	t_ms_envp	*envp;
	t_ms_envp	*new_envp;
	int			i;

	i = 0;
	envp = *head;
	while ((&envp[i])->key)
		i++;
	new_envp = ft_calloc(i + 2, sizeof(t_ms_envp));
	if (!new_envp)
		return (MALLOC_FAIL);
	i = 0;
	while (envp[i].key)
	{
		new_envp[i].key = envp[i].key;
		new_envp[i].value = envp[i].value;
		i++;
	}
	new_envp[i].key = key;
	new_envp[i].value = value;
	free(*head);
	*head = new_envp;
	return (NO_ERROR);
}

t_err	add_value_to_envp(t_ms_envp **ms_envp, char *key, char *value)
{
	if (!key_exists(key, *ms_envp))
	{
		if (add_to_ms_envp(key, value, ms_envp) == MALLOC_FAIL)
		{
			free(key);
			return (MALLOC_FAIL);
		}
		return (NO_ERROR);
	}
	replace_value(key, value, *ms_envp);
	free (key);
	return (NO_ERROR);
}
