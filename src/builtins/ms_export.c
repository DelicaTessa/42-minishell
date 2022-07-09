/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:33:50 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/11 17:50:31 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <libft.h>
#include <envp_to_var.h>
#include <envp_utils.h>
#include <lexer_utils.h>
#include <ms_export_sort.h>

int	is_export_key(char *key)
{
	size_t	i;

	i = 0;
	if (!key || !*key)
		return (0);
	if (ft_isdigit(key[0]) || key[0] == '-')
		return (0);
	while (key[i] && char_is_allowed(key[i], "'=\"-#+^~.|&@!;()<>*\\"))
		i++;
	if (ft_strlen(key) == i)
		return (1);
	return (0);
}

int	export_error_msg(char *str)
{
	if (str[0] == '-' && str[1] != '\0')
	{
		ft_putstr_fd("minishell: export: -", 2);
		ft_putchar_fd(str[1], 2);
		ft_putstr_fd(": invalid option\n", 2);
		ft_putstr_fd("export: usage: export [name[=value] ...]\n", 2);
		return (2);
	}
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

t_err	export_get_env_key(const char *str, char **return_key)
{
	int		i;

	*return_key = NULL;
	i = 0;
	if (ft_isdigit(*str))
		return (KEY_ERR);
	while (char_is_allowed(str[i], "=+\0") && !ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '=')
		return (KEY_ERR);
	*return_key = ft_calloc(i + 1, 1);
	if (!*return_key)
		return (MALLOC_FAIL);
	ft_strlcpy(*return_key, str, i + 1);
	return (NO_ERROR);
}

int	ms_export(char **argv, t_envi *envi)
{
	int		i;
	char	*key;
	int		exitcode;

	if (!argv[1])
		return (single_export(envi->ms_envp));
	exitcode = 0;
	i = 1;
	while (argv[i])
	{
		if (export_get_env_key(argv[i], &key) == MALLOC_FAIL)
			return (-1);
		if (!is_export_key(key))
		{
			ft_free_str(&key);
			exitcode = export_error_msg(argv[i]);
		}
		else
			parse_and_add_to_envp(argv[i], &envi->ms_envp, key);
		i++;
	}
	if (ms_envp_to_var(envi->ms_envp, &envi->var) == MALLOC_FAIL)
		return (-1);
	return (exitcode);
}
