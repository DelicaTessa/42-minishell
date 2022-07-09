/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:45 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/03/17 22:32:34 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <datatypes.h>
#include <tree.h>
#include <syntax_pass.h>
#include <parser_utils.h>
#include <parser_tree_utils.h>

t_err	root_pass(t_token_list *list, t_tree **root)
{
	(void)list;
	(void)root;
	if (next_branch(list))
		add_tree_node(PIPE, root, NULL);
	else
		add_tree_node(NO_PIPE, root, NULL);
	return (NO_ERROR);
}

t_err	redir_pass(t_token_list *list, t_tree **root)
{
	char	**split;

	while (list && list->type != TOK_PIPE)
	{
		if (list->type == TOK_WORD)
		{
			list = list->next;
			continue ;
		}
		split = make_split(list->next, 1);
		if (!split)
			return (MALLOC_FAIL);
		else if (list->type == TOK_REDIR_IN)
			add_tree_node(REDIR_IN, root, split);
		else if (list->type == TOK_REDIR_OUT)
			add_tree_node(REDIR_OUT, root, split);
		else if (list->type == TOK_APPEND)
			add_tree_node(REDIR_APP, root, split);
		else if (list->type == TOK_HERE_DOC)
			add_tree_node(HERE_DOC, root, split);
		list = list->next;
		list->is_parsed = TRUE;
	}
	return (NO_ERROR);
}

t_err	cmd_pass(t_token_list *list, t_tree **root)
{
	t_token_list	*node;
	int				word_count;
	char			**split;

	node = list;
	word_count = 0;
	while (node)
	{
		if (node->type == TOK_WORD && !node->is_parsed)
			word_count++;
		node = node->next;
	}
	split = create_cmd_split(list, word_count);
	if (!split)
		return (MALLOC_FAIL);
	add_tree_node(CMD, root, split);
	return (NO_ERROR);
}

t_err	parser(char *line, t_curr_input *input, t_envi *info)
{
	t_token_list	*list;
	t_tree			**root;

	(void)line;
	(void)info;
	list = input->lexer;
	root = &input->tree;
	if (!list)
		return (printf(RED "[parser] Empty t_token_list\n" RESET));
	if (pipe_syntax_pass(list) != NO_ERROR)
		return (SYNTAX_ERR);
	while (list)
	{	
		if (redir_syntax_pass(list) != NO_ERROR)
			return (SYNTAX_ERR);
		root_pass(list, root);
		redir_pass(list, root);
		cmd_pass(list, root);
		list = next_branch(list);
		if (list && list->type == TOK_PIPE)
			list = list->next;
	}
	return (NO_ERROR);
}
