/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dollar_tokens.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/17 15:46:44 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:43:50 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <builtin_utils.h>
#include <token_utils.h>
#include <dollar_tokens_utils.h>

t_err	add_literal_dollar(t_token_list **list)
{
	char			*str;
	t_token_list	*new_token;

	str = ft_strdup("$");
	if (!str)
		return (MALLOC_FAIL);
	new_token = create_token(TOK_WORD, str);
	if (!new_token)
	{
		free (str);
		return (MALLOC_FAIL);
	}
	add_to_tokenlist(list, new_token);
	return (NO_ERROR);
}

t_err	exitcode_token(const char *dquote, int *j, t_token_list **list)
{
	char	*question;

	(void)dquote;
	(void)j;
	question = ft_strdup("?");
	if (!question)
		return (MALLOC_FAIL);
	if (add_new_token_to_list(list, TOK_DOLLAR, NULL) == MALLOC_FAIL)
	{
		free(question);
		return (MALLOC_FAIL);
	}
	if (add_new_token_to_list(list, TOK_WORD, question) == MALLOC_FAIL)
	{
		free(question);
		return (MALLOC_FAIL);
	}
	return (NO_ERROR);
}

t_err	dquote_dollar_token(const char *dquote, int *j, t_token_list **list)
{
	char	*key;

	*j = *j + 1;
	if (dquote[*j] == '\0' || ft_isspace(dquote[*j]))
		return (add_literal_dollar(list));
	else if (ft_isdigit(dquote[*j]))
	{
		*j = *j + 1;
		return (NO_ERROR);
	}
	else if (dquote[*j] == '?')
	{
		*j = *j + 1;
		return (exitcode_token(dquote, j, list) == MALLOC_FAIL);
	}
	if (get_env_key(&dquote[*j], &key) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	if (key)
	{
		add_new_token_to_list(list, TOK_DOLLAR, NULL);
		add_new_token_to_list(list, TOK_WORD, key);
		*j = *j + ft_strlen(key);
	}
	return (NO_ERROR);
}

t_err	dollar_token(const char *line, int *i, t_token_list **list)
{
	t_token_list	*new_token;

	*i = *i + 1;
	if (line[1] == '\0' || ft_isspace(line[1]))
		return (add_literal_dollar(list));
	else
	{
		if (ft_isdigit(line[1]))
		{
			*i = *i + 1;
			return (NO_ERROR);
		}
		if (line[1] == '?')
		{
			*i = *i +1;
			return (exitcode_token(line, i, list));
		}
	}
	new_token = create_token(TOK_DOLLAR, NULL);
	if (!new_token)
		return (MALLOC_FAIL);
	add_to_tokenlist(list, new_token);
	return (NO_ERROR);
}

t_err	expand_dquote(const char *dquote, t_token_list **list)
{
	int		j;

	while (*dquote)
	{
		j = 0;
		while (dquote[j] && dquote[j] != '$')
			j++;
		if (j > 0)
			if (put_dquote_token(dquote, list, j) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		if (dquote[j] == '$')
		{
			if (dquote_dollar_token(dquote, &j, list) == MALLOC_FAIL)
				return (MALLOC_FAIL);
		}
		dquote += j;
	}
	return (NO_ERROR);
}
