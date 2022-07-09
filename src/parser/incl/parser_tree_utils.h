/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_tree_utils.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 22:34:14 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:34:15 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TREE_UTILS_H
# define PARSER_TREE_UTILS_H

t_tree			*next_tree(t_tree *tree);
int				count_branches(t_token_list *list);
t_token_list	*next_branch(t_token_list *list);

#endif