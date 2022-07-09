/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:52 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/14 13:38:53 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

char	**make_split(t_token_list *list, int word_amount);
void	ft_free_partial_split(char ***split, int failed_i);
char	**create_cmd_split(t_token_list *list, int word_count);

#endif