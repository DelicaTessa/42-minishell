/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:37 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 23:43:25 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <datatypes.h>
#include <lexer.h>
#include <lexer_utils.h>
#include <token_utils.h>

t_err	redir_in_token(const char *input, int *i, t_token_list **list)
{
	t_token_list	*new_token;

	if (input[1] == '<')
	{
		new_token = create_token(TOK_HERE_DOC, NULL);
		*i = *i + 2;
	}
	else
	{
		new_token = create_token(TOK_REDIR_IN, NULL);
		*i = *i + 1;
	}
	if (!new_token)
		return (MALLOC_FAIL);
	add_to_tokenlist(list, new_token);
	if (!*list)
		return (MALLOC_FAIL);
	return (NO_ERROR);
}

t_err	redir_out_token(const char *input, int *i, t_token_list **list)
{
	t_token_list	*new_token;

	if (input[1] == '>')
	{
		new_token = create_token(TOK_APPEND, NULL);
		*i = *i + 2;
	}
	else
	{
		new_token = create_token(TOK_REDIR_OUT, NULL);
		*i = *i + 1;
	}
	if (!new_token)
		return (MALLOC_FAIL);
	add_to_tokenlist(list, new_token);
	if (!*list)
		return (MALLOC_FAIL);
	return (NO_ERROR);
}

t_err	pipe_token(char *input, int *i, t_token_list **list)
{
	t_token_list	*new_token;

	if (input[1] == '|')
		return (syntax_err_lexer((char)DOUBLE_PIPE));
	new_token = create_token(TOK_PIPE, NULL);
	if (!new_token)
		return (MALLOC_FAIL);
	add_to_tokenlist(list, new_token);
	if (!*list)
		return (MALLOC_FAIL);
	*i = *i + 1;
	return (NO_ERROR);
}

char	*save_word(const char *input)
{
	char	*word;
	int		i;

	i = 0;
	while (char_is_allowed(input[i], "<>|$';\"\\[]{}()") && \
			!ft_isspace(input[i]))
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, input, i + 1);
	return (word);
}

t_err	word_token(const char *input, int *i, t_token_list **list)
{
	t_token_list	*new_token;
	char			*word;

	word = save_word(input);
	if (!word)
		return (MALLOC_FAIL);
	new_token = create_token(TOK_WORD, word);
	if (!new_token)
	{
		free (word);
		return (MALLOC_FAIL);
	}
	add_to_tokenlist(list, new_token);
	*i = *i + ft_strlen(new_token->data);
	return (NO_ERROR);
}
