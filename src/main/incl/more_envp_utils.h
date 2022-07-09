/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_envp_utils.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 15:05:25 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 15:05:26 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORE_ENVP_UTILS_H
# define MORE_ENVP_UTILS_H

char	*point_to_value(char *str);
t_err	add_value_to_envp(t_ms_envp **ms_envp, char *key, char *value);

#endif
