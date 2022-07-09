/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tree_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:39:13 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/14 13:39:14 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_UTILS_H
# define TREE_UTILS_H

void	clean_tree(t_tree **head_tree);
t_tree	*next_root_node(t_tree *tree);
t_tree	*get_next_node(t_tree *tree);
t_tree	*last_root_node(t_tree *tree);

#endif
