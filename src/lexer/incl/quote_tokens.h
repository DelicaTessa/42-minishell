/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_tokens.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 21:23:32 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_TOKENS_H
# define QUOTE_TOKENS_H

char	*save_quote(const char *line);
t_err	quote_token(const char *line, int *i, t_token_list **list);
char	save_dquote(const char *line);
t_err	dquote_token(const char *line, int *i, t_token_list **list);

#endif