/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_cd_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:18:14 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/06 15:18:15 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_CD_UTILS_H
# define MS_CD_UTILS_H

typedef struct s_hard_strings
{
	char	*pwd;
	char	*oldpwd;
}			t_hard_strings;

t_hard_strings	init_strings(void);
void			remove_dir(char parse_path[512]);
int				add_slash(char parse_path[512]);
int				add_path_chunk(char parse_path[512], char *path);

#endif