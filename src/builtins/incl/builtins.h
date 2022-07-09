/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 14:10:07 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/01 18:11:25 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <datatypes.h>
# include <free_envp.h>
# include <tree_utils.h>
# include <libft.h>

int			ft_check_builtin(t_tree *tree, t_envi *envi);
void		ft_check_export(t_tree *tree, t_envi *envi);
int			ft_check_builtin_child(t_tree *tree, t_envi *envi, \
				t_executor *exec);
int			ft_check_builtin_add(t_tree *tree, t_envi *envi, int i);

int			ft_builtin_echo(t_envi *envi, t_tree *tree);
int			ft_handle_echo(t_tree *tree, int i, int err, int check);

void		ft_exit_numeric(t_tree *tree, t_envi *envi, t_executor *exec);
int			ft_isplus(char *str);
int			ft_check_isalpha(char *str);
int			ft_check_minus_plus(char *str);
int			ft_check_isdigit(char *str);

int			ft_exit(t_tree *tree, t_envi *envi, t_executor *exec);
void		ft_exit_multi_arg(t_tree *tree, t_envi *envi, int i, \
				t_executor *exec);
void		ft_exit_one_arg(t_tree *tree, t_envi *envi, int i, \
				t_executor *exec);
void		ft_exit_one_arg_plus(t_tree *tree, t_envi *envi, t_executor *exec);
void		ft_exit_one_range(t_tree *tree, t_envi *envi, t_executor *exec);

long long	ft_atoi_exit(const char *str);
void		ft_exit_free(t_tree *tree, t_executor *exec, t_envi *envi);

int			ft_pwd_builtin(t_envi *envi);

int			ft_builtin_cd(t_tree *tree, t_envi *envi);

#endif