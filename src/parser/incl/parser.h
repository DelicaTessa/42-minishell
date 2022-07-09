/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:55 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/14 13:38:56 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_tree	*next_tree(t_tree *tree);
t_err	parser(char *line, t_curr_input *input, t_envi *info);

typedef struct s_parse_info
{
	int	pipe_amount;
}			t_parse_info;

#endif