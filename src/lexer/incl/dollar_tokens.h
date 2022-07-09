/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dollar_tokens.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:51:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 21:23:40 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOLLAR_TOKENS_H
# define DOLLAR_TOKENS_H

t_err	dquote_dollar_token(const char *dquote, int *j, t_token_list **list);
t_err	expand_dquote(const char *dquote, t_token_list **list);
t_err	dollar_token(const char *line, int *i, t_token_list **list);

#endif
