/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_errors.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 16:15:18 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:48:16 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>

int	add_string2(char *perror_str, char *string2, int rv)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(perror_str, ": ");
	free (perror_str);
	if (!temp)
		return (-1);
	temp2 = ft_strjoin(temp, string2);
	free(temp);
	if (!temp2)
		return (-1);
	perror(temp2);
	free(temp2);
	return (rv);
}

int	ms_perror(char *perror_str, char *string, char *string2, int rv)
{
	char	*temp;
	char	*temp2;

	if (perror_str)
	{
		if (string)
		{
			temp = ft_strjoin(perror_str, ": ");
			if (!temp)
				return (-1);
			temp2 = ft_strjoin(temp, string);
			free(temp);
			if (!temp2)
				return (-1);
			if (string2)
				return (add_string2(temp2, string2, rv));
			perror(temp2);
			free(temp2);
		}
		else
			perror(perror_str);
	}
	return (rv);
}
