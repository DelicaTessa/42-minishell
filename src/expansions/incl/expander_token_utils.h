/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_token_utils.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:12:52 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:07:27 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_TOKEN_UTILS_H
# define EXPANDER_TOKEN_UTILS_H

t_err	join_head_token(t_token_list **list, t_token_type resulting_type);
t_err	join_token(t_token_list *list, t_token_type resulting_type);
void	cut_head_token(t_token_list **head);
void	cut_token(t_token_list *list);

#endif
