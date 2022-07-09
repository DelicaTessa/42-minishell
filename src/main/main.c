/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:04 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/10 22:03:22 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <datatypes.h>
#include <init.h>
#include <executor.h>
#include <free_envp.h>
#include <ms_signals.h>
#include <builtins.h>
#include <input.h>

int	do_loop(t_curr_input *curr_input, t_envi *envi)
{
	char	*input;
	t_err	rv;

	while (1)
	{
		init_signals();
		if (get_input(envi, &input) == MALLOC_FAIL)
			return (-1);
		if (!input)
			continue ;
		rv = process_input(input, curr_input, envi);
		free (input);
		if (rv != NO_ERROR)
		{
			clean_tree(&curr_input->tree);
			clean_lexer(&curr_input->lexer);
			if (rv == MALLOC_FAIL)
				exit (-1);
			continue ;
		}
		ignore_signals();
		ft_start_tree(envi, &curr_input->tree);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_envi			envi;
	t_curr_input	curr_input;

	(void)argc;
	(void)argv;
	if (ms_init(envp, &envi) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	ft_bzero(&curr_input, sizeof(t_curr_input));
	return (do_loop(&curr_input, &envi));
}
