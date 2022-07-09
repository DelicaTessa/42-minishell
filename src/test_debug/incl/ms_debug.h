/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_debug.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:39:01 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 17:27:58 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_DEBUG_H
# define MS_DEBUG_H

void	print_ms_envp(void *custom_envp);
void	print_split(char **split);
void	print_tokens(t_token_list *token_list);
void	print_leave(t_tree *tree);
void	print_full_tree(t_tree *tree);

#endif