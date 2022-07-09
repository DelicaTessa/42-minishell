/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 10:28:11 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/29 13:22:40 by tessaclemen   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <ms_signals.h>
#include <term_settings.h>

static t_bool	delimiter_found(char *delimiter, char *line)
{
	if (!ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1))
		return (TRUE);
	return (FALSE);
}

int	make_here_doc(char *delimiter)
{
	int		fd;
	char	*line;

	fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		else if (delimiter_found(delimiter, line))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	return (open(".here_doc", O_RDONLY));
}

int	ft_redirs_loop_two(t_tree *tree, t_executor *exec, t_envi *envi)
{
	if (tree->type == REDIR_APP)
	{
		exec->fd_out[1] = open(tree->data[0], \
			O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (access(tree->data[0], W_OK))
			ft_redir_error(tree, exec->fd_out[1], envi);
		dup2(exec->fd_out[1], STDOUT_FILENO);
		close(exec->fd_out[1]);
	}
	if (tree->type == HERE_DOC && tree->left_node->type != HERE_DOC)
	{
		restore_term_settings(&envi->termios_p);
		set_term_settings();
		init_here_doc_signals();
		if (tree->prev_node->type == PIPE && !prev_heredoc_exists(tree))
			close(exec->fd_in[0]);
		exec->fd_in[0] = make_here_doc(tree->data[0]);
		dup2(exec->fd_in[0], STDIN_FILENO);
		close(exec->fd_in[0]);
		unlink(".here_doc");
	}
	return (0);
}

int	ft_redirs_loop(t_tree *tree, t_executor *exec, t_envi *envi)
{
	if (tree->type == REDIR_IN)
	{
		exec->fd_in[0] = open(tree->data[0], O_RDONLY);
		if (access(tree->data[0], F_OK))
			ft_redir_in_error(tree, envi);
		if (access(tree->data[0], R_OK))
			ft_redir_error(tree, exec->fd_in[0], envi);
		dup2(exec->fd_in[0], STDIN_FILENO);
		close(exec->fd_in[0]);
	}
	if (tree->type == REDIR_OUT)
	{
		exec->fd_out[1] = open(tree->data[0], \
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (access(tree->data[0], W_OK))
			ft_redir_error(tree, exec->fd_out[1], envi);
		dup2(exec->fd_out[1], STDOUT_FILENO);
		close(exec->fd_out[1]);
	}
	ft_redirs_loop_two(tree, exec, envi);
	return (0);
}
