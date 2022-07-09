/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_signals.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 14:36:39 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 14:37:07 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNALS_H
# define MS_SIGNALS_H

void	init_here_doc_signals(void);
void	init_signals(void);
void	restore_signals(void);
void	ignore_signals(void);

#endif
