/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   term_settings.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:36:29 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 14:36:59 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_SETTINGS_H
# define TERM_SETTINGS_H

void	set_term_settings(void);
void	restore_term_settings(struct termios *termios_p);
void	save_term_settings(struct termios *termios_p);

#endif
