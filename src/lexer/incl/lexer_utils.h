/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:44 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/14 13:37:45 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

t_err			syntax_err_lexer(char token);
t_bool			char_is_allowed(int c, char *not_allowed);
void			clean_lexer(t_token_list **list);

#endif