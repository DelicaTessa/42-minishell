/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gnl.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 14:58:36 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/12 12:03:23 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

char	*ft_strnjoin_freeold(char *buffer, char *line, int n)
{
	int		old_line_len;
	char	*new_line;

	old_line_len = gnl_strlen(line);
	new_line = (char *)malloc(old_line_len + n + 1);
	if (!new_line)
	{
		if (line)
		{
			free(line);
			line = NULL;
		}
		return (NULL);
	}
	new_line[old_line_len + n] = '\0';
	gnl_cpy(line, new_line, old_line_len);
	gnl_cpy(buffer, new_line + old_line_len, n);
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (new_line);
}

void	shift_buffer(char *buffer, int nl_index)
{
	int	shift_len;

	shift_len = gnl_strlen(buffer + nl_index + 1);
	gnl_cpy(buffer + nl_index + 1, buffer, shift_len);
	buffer[shift_len] = '\0';
}

t_bool	newline_in_buffer(char *buffer, char **line)
{
	int		nl_index;
	char	*new_line;

	new_line = NULL;
	nl_index = find_nl_index(buffer);
	if (nl_index >= 0)
	{
		new_line = ft_strnjoin_freeold(buffer, *line, nl_index);
		shift_buffer(buffer, nl_index);
		*line = new_line;
		return (TRUE);
	}
	new_line = ft_strnjoin_freeold(buffer, *line, gnl_strlen(buffer));
	shift_buffer(buffer, gnl_strlen(buffer));
	*line = new_line;
	return (FALSE);
}

char	*ft_gnl(int fd)
{
	int			read_return;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	read_return = 1;
	if (fd == -1)
		return (NULL);
	if (*buffer && newline_in_buffer(buffer, &line))
		return (line);
	while (read_return)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		buffer[read_return] = '\0';
		if (newline_in_buffer(buffer, &line))
			return (line);
	}
	if (line)
		free(line);
	return (NULL);
}
