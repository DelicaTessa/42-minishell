/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   variable_expander.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:12:58 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:07:03 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_EXPANDER_H
# define VARIABLE_EXPANDER_H

t_err	expand_dollars(t_token_list **list, t_envi *info, t_token_type type);

#endif