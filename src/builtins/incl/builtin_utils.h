/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_utils.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:36:44 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 19:51:54 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H

t_err	get_env_key(const char *str, char **return_key);
t_err	get_env_value(t_ms_envp *envp, char *key, char **value_ptr);

#endif