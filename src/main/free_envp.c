/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_envp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:16:05 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:42:21 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>

void	free_envp(t_ms_envp *ms_envp)
{
	int			i;

	if (!ms_envp)
	{
		printf(RED "[free_envp] ms_envp == NULL ?!??\n" RESET);
		return ;
	}
	i = 0;
	while (ms_envp[i].key)
	{
		ft_free_str(&ms_envp[i].key);
		ft_free_str(&ms_envp[i].value);
		i++;
	}
	free (ms_envp);
}
