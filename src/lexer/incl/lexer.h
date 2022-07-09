/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:46 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/14 13:54:25 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define DOUBLE_PIPE 2

t_err			lexer(char *line, t_curr_input *input, t_envi *info);

#endif