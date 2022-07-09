/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   datatypes.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jcorneli <jcorneli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:38:14 by jcorneli      #+#    #+#                 */
/*   Updated: 2022/05/01 17:39:23 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPES_H
# define DATATYPES_H

# include <termios.h>
# include <ansi_color_codes.h>
# include <stddef.h>

# define PROMPT "minishell-1.1$ "

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

typedef enum e_err
{
	NO_ERROR,
	MALLOC_FAIL,
	INPUT_ERR,
	KEY_ERR,
	NO_VALUE,
	NO_KEY,
	SYNTAX_ERR,
	EMPTY,
	DEFAULT_ERR
}		t_err;

typedef enum s_nodetype
{
	PIPE,
	NO_PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APP,
	HERE_DOC,
	CMD
}		t_nodetype;

typedef enum s_token_type
{
	TOK_WORD,
	TOK_PIPE,
	TOK_QUOTE,
	TOK_DQUOTE,
	TOK_DOLLAR,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_APPEND,
	TOK_HERE_DOC,
	TOK_SPACE,
	TOK_NO_TOKENS,
	TOK_ERROR
}		t_token_type;

typedef struct s_tree
{
	int				id;
	t_nodetype		type;
	char			**data;
	struct s_tree	*left_node;
	struct s_tree	*right_node;
	struct s_tree	*prev_node;
}		t_tree;

typedef struct s_node
{
	t_nodetype		type;
	char			**arg;
}		t_node;

typedef struct s_token_list
{
	int					id;
	t_token_type		type;
	t_bool				is_parsed;
	char				*data;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}		t_token_list;

typedef struct s_curr_input
{
	t_token_list	*lexer;
	t_tree			*tree;
}		t_curr_input;

typedef struct s_executor
{
	int	fd_in[2];
	int	fd_out[2];
	int	index;
	int	builtin_check;
}	t_executor;

typedef struct s_ms_envp
{
	char	*key;
	char	*value;
}		t_ms_envp;

typedef struct s_envi
{
	t_ms_envp		*ms_envp;
	char			**var;
	struct termios	termios_p;
	int				exitcode;
	t_executor		*exec;
	t_tree			**loc_tree_ptr;
}		t_envi;

#endif