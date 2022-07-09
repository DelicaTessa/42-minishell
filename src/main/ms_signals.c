/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_signals.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 14:55:05 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/10 23:10:20 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stddef.h>
#include <signal.h>
#include <libft.h>

void	new_prompt(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_here_doc_signals(void)
{
	struct sigaction	sig_slash;
	struct sigaction	sig_c;

	ft_bzero(&sig_slash, sizeof(struct sigaction));
	ft_bzero(&sig_c, sizeof(struct sigaction));
	sig_slash.sa_handler = SIG_IGN;
	sig_c.sa_handler = SIG_DFL;
	sigaction(SIGQUIT, &sig_slash, NULL);
	sigaction(SIGINT, &sig_c, NULL);
}

void	restore_signals(void)
{
	struct sigaction	sig;

	ft_bzero(&sig, sizeof(struct sigaction));
	sig.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}

void	ignore_signals(void)
{
	struct sigaction	sig;

	ft_bzero(&sig, sizeof(struct sigaction));
	sig.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}

void	init_signals(void)
{
	struct sigaction	sig_c;
	struct sigaction	sig_slash;

	ft_bzero(&sig_c, sizeof(struct sigaction));
	ft_bzero(&sig_slash, sizeof(struct sigaction));
	sig_c.sa_handler = new_prompt;
	sig_slash.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig_c, NULL);
	sigaction(SIGQUIT, &sig_slash, NULL);
}
