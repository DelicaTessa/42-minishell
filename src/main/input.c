/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 23:10:57 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/11 00:07:06 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <input.h>
#include <lexer.h>
#include <expander.h>
#include <parser.h>
#include <term_settings.h>
#include <lexer_utils.h>
#include <free_envp.h>

t_err	process_input(char *line, t_curr_input *input, t_envi *info)
{
	int						i;
	t_err					err;
	static t_proc_input_ptr	proc_funptr[3] = {
	[0] = lexer,
	[1] = expander,
	[2] = parser
	};

	i = 0;
	while (i < 3)
	{
		err = proc_funptr[i](line, input, info);
		if (err != NO_ERROR)
		{
			if (err == SYNTAX_ERR)
				info->exitcode = 258;
			return (err);
		}
		i++;
	}
	clean_lexer(&input->lexer);
	return (NO_ERROR);
}

int	ft_exit_sig(t_envi *envi)
{
	restore_term_settings(&envi->termios_p);
	rl_replace_line("exit", 0);
	rl_on_new_line();
	rl_redisplay();
	write(1, "\n", 1);
	ft_free_split(&envi->var);
	free_envp(envi->ms_envp);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit(0);
}

t_err	get_input(t_envi *envi, char **input_ptr)
{
	char	*temp;

	set_term_settings();
	rl_replace_line("", 0);
	*input_ptr = readline(YEL PROMPT RESET);
	restore_term_settings(&envi->termios_p);
	if (*input_ptr && (*input_ptr)[0])
	{
		temp = *input_ptr;
		*input_ptr = ft_strtrim_white(*input_ptr);
		free(temp);
		if (!*input_ptr)
			return (MALLOC_FAIL);
		add_history(*input_ptr);
	}
	else if (!*input_ptr)
		ft_exit_sig(envi);
	return (NO_ERROR);
}
