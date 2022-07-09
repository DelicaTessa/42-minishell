/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 13:07:47 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/28 18:10:20 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <datatypes.h>
# include <init.h>
# include <lexer.h>
# include <lexer_utils.h>
# include <builtins.h>
# include <builtin_utils.h>
# include <tree.h>
# include <tree_utils.h>
# include <parser.h>
# include <paths.h>
# include <ms_debug.h>
# include <signal.h>

void		*ft_free_paths(char **first, char **second, char *third);
char		**ft_edit_paths(char **paths, char **arg, int i);
char		*get_path_env(char *temp);
char		*find_path_env(char **envp, t_envi *envi);
int			ft_get_paths(t_envi *envi, char **arg);

void		ft_start_tree(t_envi *envi, t_tree **tree);
t_executor	*ft_init_exec(void);

int			ft_handle_tree(t_envi *envi, t_tree *tree, t_executor *exec);
void		ft_handle_heredoc(t_executor *exec, t_envi *envi);
int			ft_close_fd(int fd[2]);
int			ft_copy_fd(t_executor *exec);
int			ft_wait_on_children(t_executor *exec, t_envi *envi);

int			ft_handle_loop(t_envi *envi, t_executor *exec, t_tree *tree);
int			ft_handle_loop_two(t_envi *envi, t_executor *exec, t_tree *tree);
void		ft_close_all(t_executor *exec);
int			ft_pipe_start_util(t_tree *tree, pid_t pid);

int			ft_exec_cmd(char *path, char **envp, char **arg, t_envi *envi);
int			ft_check_access(char *path, char **envp, char **arg, t_envi *envi);
char		*ft_search_bins(char **exec_paths);
int			ft_acces_and_exec(t_envi *envi, char **arg, char **paths);

int			ft_nopipe_end(t_tree *tree, t_envi *envi, t_executor *exec);
int			ft_pipe_inbetween(t_envi *envi, t_tree *tree, t_executor *exec);
int			ft_nopipe_start(t_envi *envi, t_tree *tree, t_executor *exec);
int			ft_pipe_start(t_envi *envi, t_tree *tree, t_executor *exec);
int			ft_nopipe_end_util(t_tree *tree, pid_t pid, int status);

void		ft_helper_nopipe_end(t_tree *tree, t_envi *envi, t_executor *exec);
void		ft_helper_pipe_inbetween(t_tree *tree, t_envi *envi, \
			t_executor *exec);
void		ft_helper_pipe_start(t_tree *tree, t_envi *envi, t_executor *exec);
void		ft_helper_nopipe_start(t_tree *tree, t_envi *envi);
int			prev_heredoc_exists(t_tree *tree);

char		*ft_gnl(int fd);
t_bool		newline_in_buffer(char *buffer, char **line);
void		shift_buffer(char *buffer, int nl_index);
char		*ft_strnjoin_freeold(char *buffer, char *line, int n);

void		gnl_cpy(char *src, char *dest, int n);
int			gnl_strlen(const char *str);
int			find_nl_index(const char *str);

int			ft_redirs_loop(t_tree *tree, t_executor *exec, t_envi *envi);
int			ft_redirs_loop_two(t_tree *tree, t_executor *exec, t_envi *envi);

int			ft_start_builtin(t_tree *tree, t_envi *envi, t_executor *exec);
int			ft_check_nonwriteable(t_tree *tree, t_envi *envi, t_executor *exec);

int			ft_error_exec(int code, int *fd, t_envi *envi);
int			ft_redir_error(t_tree *tree, int fd, t_envi *envi);
int			ft_redir_in_error(t_tree *tree, t_envi *envi);

void		ft_dir_exit(char **arg, t_envi *envi, char **paths);
int			ft_parse_dir_loop(char *str);
int			ft_is_dir(char **envp, char **arg, t_envi *envi, char **paths);
int			ft_parse_dir(char **envp, char **arg, t_envi *envi, char **paths);
void		ft_cmd_exit(char **arg, t_envi *envi, char **paths);
void		process_signal(int sig, int *exitcode, int fd[2]);

void		free_envi(t_envi *envi);
void		free_envi_parent(t_envi *envi);

#endif
