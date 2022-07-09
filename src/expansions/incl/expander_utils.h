/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:12:49 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:07:48 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_UTILS_H
# define EXPANDER_UTILS_H

t_err	quotes_to_words(t_token_list **list, t_envi *info, t_token_type type);
t_err	rm_token_type(t_token_list **list, t_envi *info, t_token_type type);
t_err	rm_double_tokens(t_token_list **list, t_envi *info, t_token_type type);

#endif