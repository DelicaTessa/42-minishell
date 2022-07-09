/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:37:22 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/04/07 22:25:44 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <datatypes.h>
#include <lexer.h>
#include <lexer_utils.h>
#include <tokens.h>
#include <quote_tokens.h>
#include <dollar_tokens.h>
#include <space_tokens.h>

static t_err	tokenize(char *input, int *i, t_token_list **list)
{
	if (*input == '<')
		return (redir_in_token(input, i, list));
	else if (*input == '>')
		return (redir_out_token(input, i, list));
	else if (*input == '|')
		return (pipe_token(input, i, list));
	else if (*input == '$')
		return (dollar_token(input, i, list));
	else if (*input == '\'')
		return (quote_token(input, i, list));
	else if (*input == '"')
		return (dquote_token(input, i, list));
	else
		return (word_token(input, i, list));
}

t_err	lexer(char *line, t_curr_input *input, t_envi *info)
{
	t_token_list	**list;
	int				i;
	t_err			err;

	(void)info;
	i = 0;
	list = &input->lexer;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			space_token(&line[i], &i, list);
		else if (!char_is_allowed(line[i], "\\;~{}[()^%#&"))
			return (syntax_err_lexer(line[i]));
		else
		{
			err = tokenize(&line[i], &i, list);
			if (err != NO_ERROR)
				return (err);
		}
	}
	return (NO_ERROR);
}
