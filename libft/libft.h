/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tclement <tclement@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 14:30:44 by tclement      #+#    #+#                 */
/*   Updated: 2022/04/07 23:40:01 by jcorneli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
// # include <stdlib.h>
//# include <unistd.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *data);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
t_list				*ft_locate_list(t_list *begin_list, unsigned int nbr);
t_list				*ft_list_find(t_list *begin_list, void *data_ref, \
					int (*cmp)());
size_t				ft_strlen(const char *s);
size_t				ft_str_array_len(char **strs);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char	*s1, const char *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strtrim_white(char const *s);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstdel_if(t_list **begin_list, void *data_ref,
						int (*cmp)(), void (*free_fct)(void *));
void				ft_lstpush_back(t_list **begin_list, void *data);
void				ft_lstclear(t_list *begin_list, void (*free_fct)(void **));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_free_dbl_ptr(void **ptr);
void				ft_free_partial_split(char ***split, int failed_i);
void				ft_free_split(char ***split);
void				ft_free_str(char **str);
int					ft_lstsize(t_list *lst);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_skipspace(char const *str);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
int					ft_str_array_dup(char ***strs, size_t size, char *str);
int					ft_calloc_ptr(size_t count, size_t size, void **ptr);
int					ft_strcmp(char *s1, char *s2);

#endif
