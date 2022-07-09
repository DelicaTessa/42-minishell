/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   envp_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:36:51 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 14:36:19 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_UTILS_H
# define ENVP_UTILS_H

t_bool	key_exists(char *key, t_ms_envp *ms_envp);
t_err	replace_value(char *key, char *value, t_ms_envp *envp);
t_err	add_to_ms_envp(char *key, char *value, t_ms_envp **head);
t_err	parse_and_add_to_envp(char *str, t_ms_envp **ms_envp, char *key);

#endif