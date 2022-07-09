/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp_to_var.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:33:34 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:41:22 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>

t_err	combine_key_value(t_ms_envp *ms_envp, char **var)
{
	char	*intermediate;
	char	*combined;

	if (ms_envp->value)
	{
		intermediate = ft_strjoin(ms_envp->key, "=");
		if (!intermediate)
			return (MALLOC_FAIL);
		combined = ft_strjoin(intermediate, ms_envp->value);
		free (intermediate);
		if (!combined)
			return (MALLOC_FAIL);
	}
	else
		combined = ft_strdup(ms_envp->key);
	if (!combined)
		return (MALLOC_FAIL);
	*var = combined;
	return (NO_ERROR);
}

t_err	ms_envp_to_var(t_ms_envp *ms_envp, char ***var)
{
	int	i;
	int	j;

	if (!ms_envp)
		return (printf(RED "[ms_envp_to_var] ms_envp = NULL\n" RESET));
	i = 0;
	while (ms_envp[i].key)
		i++;
	if (*var)
		ft_free_split(var);
	*var = ft_calloc(i + 1, sizeof(char *));
	if (!*var)
		return (MALLOC_FAIL);
	j = 0;
	while (j < i)
	{
		if (combine_key_value(&ms_envp[j], &(*var)[j]) == MALLOC_FAIL)
		{
			ft_free_partial_split(var, j);
			return (MALLOC_FAIL);
		}
		j++;
	}
	return (NO_ERROR);
}
