# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jcorneli <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/24 10:42:28 by tclement      #+#    #+#                  #
#    Updated: 2022/04/13 11:10:02 by tclement      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_calloc_ptr.c \
		ft_free_dbl_ptr.c \
		ft_free_partial_split.c \
		ft_free_split.c \
		ft_free_str.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_skipspace.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_str_array_dup.c \
		ft_str_array_len.c \
		ft_strjoin.c \
		ft_strcmp.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_strtrim_white.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_find_list.c \
		ft_lstpush_back.c \
		ft_locate_list.c \

SRC_O = $(SRC:.c=.o)

BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstdelone.c \
		ft_lstdel_if.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

CC = gcc

BONUS_O = $(BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ = $(SRC_O) $(BONUS_O)
else
	OBJ = $(SRC_O)
endif

$(info )

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@echo "\033[35mCompiling library file:  $@\033[0m"
	@ar rcs $@ $^

bonus:
	@$(MAKE) WITH_BONUS=1 all

%.o: %.c $(HEADER)
	@echo "\033[34mCompiling object file:   $@\033[0m"
	@$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "\033[31mRemoving object files (libft)\033[0m"
	@rm -f $(SRC_O) $(BONUS_O)

fclean: clean
	@echo
	@echo "\033[31mRemoving binary (libft)\033[0m"
	@echo
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re bonus
