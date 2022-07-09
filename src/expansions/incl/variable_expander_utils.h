/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   variable_expander_utils.h                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:49:32 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/06 15:54:36 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_EXPANDER_UTILS_H
# define VARIABLE_EXPANDER_UTILS_H

void			create_full_string(char **str, char *data, int len);
t_token_list	*create_tailpart(char *key, char *data);
t_err			insert_tokens(t_token_list **head, char *key, char *value, \
				char *data);

#endif