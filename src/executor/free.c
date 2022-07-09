/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 17:50:32 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/25 14:30:15 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	free_envi_parent(t_envi *envi)
{
	clean_tree(envi->loc_tree_ptr);
	free(envi->exec);
}

void	free_envi(t_envi *envi)
{
	clean_tree(envi->loc_tree_ptr);
	free(envi->exec);
	ft_free_split(&envi->var);
	free_envp(envi->ms_envp);
	close(0);
	close(1);
}
