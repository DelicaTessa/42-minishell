/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 23:10:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:10:50 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef t_err(*t_proc_input_ptr)(char*, t_curr_input*, t_envi*);

t_err	process_input(char *line, t_curr_input *input, t_envi *info);
t_err	get_input(t_envi *envi, char **input_ptr);

#endif
