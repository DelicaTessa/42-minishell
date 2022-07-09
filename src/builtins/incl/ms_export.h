/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_export.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:36:53 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/06 15:26:13 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXPORT_H
# define MS_EXPORT_H

t_err	ms_export(char **argv, t_envi *envi);
int		is_export_key(char *key);

#endif
