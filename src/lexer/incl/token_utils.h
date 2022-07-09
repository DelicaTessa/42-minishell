/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:54 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/14 13:37:55 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_UTILS_H
# define TOKEN_UTILS_H

void			del_token(t_token_list *list);
t_token_list	*create_token(t_token_type type, char *data);
void			add_to_tokenlist(t_token_list **head, t_token_list *new);
t_err			add_new_token_to_list(t_token_list **head, \
				t_token_type type, char *data);

#endif