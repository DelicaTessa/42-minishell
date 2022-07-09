# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jcorneli <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/30 14:41:05 by tclement      #+#    #+#                  #
#    Updated: 2022/04/13 11:10:05 by tclement      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

MAIN_DIR	=	src/main/
MAIN_FILE	=	main.c \
				init.c \
				ms_signals.c \
				term_settings.c \
				envp_to_var.c \
				envp_utils.c \
				more_envp_utils.c \
				free_envp.c \
				input.c


LEXER_DIR	=	src/lexer/
LEXER_FILE	=	lexer.c \
				lexer_utils.c \
				tokens.c \
				quote_tokens.c \
				dollar_tokens.c \
				dollar_tokens_utils.c \
				space_tokens.c \
				token_utils.c

EXP_DIR		=	src/expansions/
EXP_FILE	=	expander.c \
				variable_expander.c \
				variable_expander_utils.c \
				expander_utils.c \
				expander_token_utils.c \
				more_exp_token_utils.c

PARSER_DIR	=	src/parser/
PARSER_FILE	=	parser.c \
				syntax_pass.c \
				parser_utils.c \
				parser_tree_utils.c

EXEC_DIR	=	src/executor/
EXEC_FILE	=	exec.c \
				paths.c \
				handle_tree.c \
				tree_loop_functions.c \
				ft_gnl.c \
				ft_gnl_utils.c \
				redirs.c \
				tree_loop_utils.c \
				start_tree.c \
				tree_loop_builtin.c \
				error.c \
				dirs.c \
				handle_tree_utils.c \
				signals_exec.c \
				free.c


BUILTIN_DIR	=	src/builtins/
BUILTIN_FILE=	builtins.c \
				builtin_utils.c \
				ms_export.c \
				ms_export_sort.c \
				ms_export_sort_utils.c \
				ms_unset.c \
				echo.c \
				exit.c \
				exit_utils.c \
				exit_atoi.c \
				pwd.c \
				ms_cd.c \
				ms_cd_utils.c \
				ms_env.c

ERROR_DIR	=	src/tree/
ERROR_FILE	=	tree.c \
				tree_utils.c

TREE_DIR	=	src/errors/
TREE_FILE	=	ms_errors.c

DEBUG_DIR	=	src/test_debug/
DEBUG_FILE	=	ms_debug.c \
				ms_debug_utils.c

SRC_DIRS	=	$(MAIN_DIR) $(LEXER_DIR) $(EXP_DIR) $(PARSER_DIR) $(EXEC_DIR) \
				$(BUILTIN_DIR) $(TREE_DIR) $(ERROR_DIR) $(DEBUG_DIR)
SRC			=	$(MAIN_FILE) $(LEXER_FILE) $(EXP_FILE) $(PARSER_FILE) $(EXEC_FILE) \
				$(BUILTIN_FILE) $(TREE_FILE) $(ERROR_FILE) $(DEBUG_FILE)

OBJ_DIR		=	obj/
OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

INCL_DIRS	=	$(addsuffix incl, $(SRC_DIRS))
INCLUDES	=	-Ilibft $(addprefix -I, $(INCL_DIRS)) -I$(shell brew --prefix readline)/include

LIB			=	-L$(shell brew --prefix readline)/lib -lreadline -Llibft -lft

CFLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

vpath %.c $(SRC_DIRS)

$(info )

all: $(NAME)

bonus: all

test:
	@echo
	@echo SRC = $(SRC)
	@echo
	@echo SRC_DIRS = $(SRC_DIRS)
	@echo
	@echo OBJ = $(OBJ)
	@echo
	@echo INCL_DIRS = $(INCL_DIRS)
	@echo
	@echo INCLUDES = $(INCLUDES)
	@echo

$(NAME): $(OBJ)
	@echo
	@echo "\033[35mBuilding libft\033[0m"
	@make bonus -C libft
	@echo
	@echo "\033[36mLinking binary file:     $@ 🐢🐚\033[0m"
	@echo
	@$(CC) $^ $(LIB) $(CFLAGS) -o $@

$(OBJ_DIR)%.o:%.c
	@mkdir -p $(@D)
	@echo "\033[34mCompiling object file:   $@\033[0m"
	@$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

libft:
	@make bonus -C libft

clean:
	@echo "\033[31mRemoving object files\033[0m"
	@echo
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mRemoving binary\033[0m"
	@echo
	@rm -f $(NAME)
	@make fclean -C libft

re: clean all

reall: fclean all

.PHONY:	all libft norme clean fclean re reall