/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_export_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:45:21 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/11 17:51:53 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <ms_export_sort_utils.h>

int	get_ms_envp_len(t_ms_envp *ms_envp)
{
	int	i;

	i = 0;
	while (ms_envp->key)
	{
		ms_envp++;
		i++;
	}
	return (i);
}

int	not_ready(int *arr, int arr_len)
{
	int	i;

	i = 0;
	while (i < arr_len)
	{
		if (*(arr + i) == 0)
			return (1);
		i++;
	}
	return (0);
}

t_err	single_export(t_ms_envp *ms_envp)
{
	int	arr_len;
	int	*arr;

	arr_len = get_ms_envp_len(ms_envp);
	if (!ms_envp)
		return (printf(RED "[single_export] ms_envp pointing to (null)..\n"));
	arr = ft_calloc(arr_len, sizeof(int));
	if (!arr)
		return (MALLOC_FAIL);
	while (not_ready(arr, arr_len))
	{
		if (print_smallest_and_mark_arr(ms_envp, arr, arr_len) == MALLOC_FAIL)
		{
			free(arr);
			return (MALLOC_FAIL);
		}
	}
	free(arr);
	return (0);
}
