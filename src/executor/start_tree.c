/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_tree.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 11:13:58 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/11 14:31:54 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	ft_start_tree(t_envi *envi, t_tree **tree)
{
	int	i;

	envi->exec = ft_init_exec();
	envi->loc_tree_ptr = tree;
	if (!envi->exec)
		ft_error_exec(5, 0, envi);
	i = ft_handle_tree(envi, *tree, envi->exec);
	if (i == 34 || i == 33)
		envi->exitcode = 1;
	unlink(".here_doc");
	free_envi_parent(envi);
}

t_executor	*ft_init_exec(void)
{	
	t_executor	*new;

	new = ft_calloc(sizeof(t_executor), 1);
	if (!new)
		return (NULL);
	new->index = 0;
	new->builtin_check = 0;
	return (new);
}

int	ft_nopipe_end_util(t_tree *tree, pid_t pid, int status)
{
	if (tree->left_node && tree->left_node->type == HERE_DOC)
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) == 1)
			return (33);
	}
	return (0);
}
