/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gnl_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 14:58:57 by tclement      #+#    #+#                 */
/*   Updated: 2022/03/12 12:03:48 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

void	gnl_cpy(char *src, char *dest, int n)
{
	int	i;

	if (!src || !dest || n < 1)
		return ;
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

int	gnl_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_nl_index(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
