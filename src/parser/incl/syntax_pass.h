/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   syntax_pass.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 22:34:17 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:34:18 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_PASS_H
# define SYNTAX_PASS_H

t_err	pipe_syntax_pass(t_token_list *list);
t_err	redir_syntax_pass(t_token_list *list);

#endif
