/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:38 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/16 16:49:42 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

typedef t_err(*t_expander_funptr)(t_token_list**, t_envi*, t_token_type);

t_err	expander(char *line, t_curr_input *input, t_envi *info);
t_err	rm_token_type(t_token_list **list, t_envi *info, t_token_type type);

#endif