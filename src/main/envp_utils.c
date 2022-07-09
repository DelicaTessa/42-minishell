/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:33:38 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:41:45 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <datatypes.h>
#include <libft.h>
#include <builtin_utils.h>
#include <more_envp_utils.h>

t_err	get_plusis_value(char *value, char *key, t_ms_envp *ms_envp, \
		char **joined)
{
	char	*old_value;
	char	*temp;

	temp = NULL;
	if (get_env_value(ms_envp, key, &old_value) == MALLOC_FAIL)
	{
		free(key);
		free(value);
		return (MALLOC_FAIL);
	}
	if (old_value && value)
	{
		temp = ft_strjoin(old_value, value);
		ft_free_str(&old_value);
		ft_free_str(&value);
		if (!temp)
			return (MALLOC_FAIL);
	}
	else if (!old_value)
		temp = value;
	*joined = temp;
	return (NO_ERROR);
}

t_err	parse_and_add_to_envp(char *str, t_ms_envp **ms_envp, char *key)
{
	char	*value;

	value = NULL;
	if (str[ft_strlen(key)] == '=' || str[ft_strlen(key)] == '+')
	{
		value = ft_strdup(point_to_value(str));
		if (!value)
		{
			free(key);
			return (MALLOC_FAIL);
		}
	}
	if (str[ft_strlen(key)] == '+')
		if (get_plusis_value(value, key, *ms_envp, &value) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	if (str[ft_strlen(key)] == '=' || str[ft_strlen(key)] == '\0')
		return (add_value_to_envp(ms_envp, key, value));
	return (NO_ERROR);
}
