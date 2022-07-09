/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:33:30 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:36:03 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <datatypes.h>
#include <lexer_utils.h>

t_err	get_env_key(const char *str, char **return_key)
{
	int		i;

	*return_key = NULL;
	i = 0;
	if (ft_isdigit(*str))
		return (KEY_ERR);
	while (char_is_allowed(str[i], "$()<>'/\\;=.\0") && !ft_isspace(str[i]))
		i++;
	*return_key = ft_calloc(i + 1, 1);
	if (!*return_key)
		return (MALLOC_FAIL);
	ft_strlcpy(*return_key, str, i + 1);
	return (NO_ERROR);
}

t_err	get_env_value(t_ms_envp *envp, char *key, char **value_ptr)
{
	int		i;

	i = 0;
	while (envp[i].key)
	{
		if (!(ft_strncmp(envp[i].key, key, ft_strlen(key) + 1)))
		{
			if (envp[i].value)
			{
				*value_ptr = ft_strdup(envp[i].value);
				if (!*value_ptr)
					return (MALLOC_FAIL);
				return (NO_ERROR);
			}
			else
			{
				*value_ptr = NULL;
				return (NO_VALUE);
			}
		}
		i++;
	}
	*value_ptr = NULL;
	return (NO_KEY);
}
