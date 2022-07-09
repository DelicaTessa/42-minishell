/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quote_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:25 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:43:36 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <datatypes.h>
#include <libft.h>
#include <lexer_utils.h>
#include <token_utils.h>
#include <dollar_tokens.h>

t_err	save_quote(const char *line, char **quote)
{
	int		i;

	i = 0;
	while (char_is_allowed(line[i], "'\0"))
		i++;
	if (line[i] != '\'')
	{
		ft_putstr_fd("minishell: syntax error open-ended ", 2);
		ft_putstr_fd("quote (unsupported)\n", 2);
		return (SYNTAX_ERR);
	}
	*quote = malloc(i + 1);
	if (!*quote)
		return (MALLOC_FAIL);
	ft_strlcpy(*quote, line, i + 1);
	return (NO_ERROR);
}

t_err	quote_token(const char *line, int *i, t_token_list **list)
{
	t_token_list	*new_token;
	char			*quote;
	t_err			err;

	err = save_quote(line + 1, &quote);
	if (err != NO_ERROR)
		return (err);
	new_token = create_token(TOK_QUOTE, quote);
	if (!new_token)
	{
		free (quote);
		return (MALLOC_FAIL);
	}
	add_to_tokenlist(list, new_token);
	*i = *i + ft_strlen(new_token->data) + 2;
	return (NO_ERROR);
}

t_err	save_dquote(const char *line, char **dquote)
{
	int		i;

	i = 0;
	while (char_is_allowed(line[i], "\"\0"))
		i++;
	if (line[i] != '"')
	{
		ft_putstr_fd("minishell: syntax error open-ended ", 2);
		ft_putstr_fd("quote (unsupported)\n", 2);
		return (SYNTAX_ERR);
	}
	*dquote = malloc(i + 1);
	if (!*dquote)
		return (MALLOC_FAIL);
	ft_strlcpy(*dquote, line, i + 1);
	return (NO_ERROR);
}

t_err	dquote_token(const char *line, int *i, t_token_list **list)
{
	t_token_list	*new_token;
	char			*dquote;
	t_err			err;

	err = save_dquote(line + 1, &dquote);
	if (err != NO_ERROR)
		return (err);
	*i = *i + ft_strlen(dquote) + 2;
	if (ft_strchr(dquote, '$'))
		return (expand_dquote(dquote, list));
	new_token = create_token(TOK_DQUOTE, dquote);
	if (!new_token)
	{
		free (dquote);
		return (MALLOC_FAIL);
	}
	add_to_tokenlist(list, new_token);
	return (NO_ERROR);
}
