/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals_exec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 10:59:34 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/12 21:17:20 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	process_signal(int sig, int *exitcode, int fd[2])
{
	if (sig == SIGINT)
	{
		if (fd)
			ft_close_fd(fd);
		*exitcode = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
	else if (sig == SIGQUIT)
	{
		if (fd)
			ft_close_fd(fd);
		*exitcode = 131;
		ft_putstr_fd("Quit: 3\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}
