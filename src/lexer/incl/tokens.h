/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:57 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 19:49:51 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

t_err	redir_in_token(const char *input, int *i, t_token_list **list);
t_err	redir_out_token(const char *input, int *i, t_token_list **list);
t_err	pipe_token(const char *input, int *i, t_token_list **list);
char	*save_word(const char *input);
t_err	word_token(const char *input, int *i, t_token_list **list);

#endif