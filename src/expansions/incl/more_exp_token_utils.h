/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_exp_token_utils.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:12:56 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:07:33 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORE_EXP_TOKEN_UTILS_H
# define MORE_EXP_TOKEN_UTILS_H

void	insert_token_after(t_token_list *list, t_token_list *new);
void	replace_head_token(t_token_list **head, t_token_list *new);
void	replace_token(t_token_list *list, t_token_list *new);

#endif
