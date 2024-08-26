/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:42:24 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/16 12:36:22 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
int					ft_abs(int k);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_char_in_str(char *s, int c);
void				*ft_free_array(void **s, int size_s);
long int			ft_htoi(char *hex_str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
int					ft_len_tab(char **s);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_max(int a, int b);
int					ft_min(int a, int b);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(const char *s);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_putchar(char c);
void				ft_free(void *data);
int					ft_wc(char *s);
int					str_in_str(char *src, char *str);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				print_err(int n, char *s, ...);

/*	FOR PRINTF: to print %[+#' '][csdiuXxp]		*/
typedef struct s_flags
{
	char			type;
	int				plus;
	int				space;
	int				hash;
}					t_flags;

int					ft_printf(const char *fmt, ...);
int					ft_parse_format_spec(const char *s, t_flags *flags);
int					ft_print_char(char c);
int					ft_print_str(const char *s);
int					ft_print_int(int d, t_flags *flags);
int					ft_print_unsigned(unsigned int u);
int					ft_print_hex(unsigned long long x, t_flags *flags);
int					ft_print_ptr(void *ptr, t_flags *flags);

/*  FOR GET_NEXT_LINE   */
char				*get_next_line(int fd);
void				copy_list_to_str(t_list *list, char *buffer);
int					is_new_line(t_list *list);
int					len_to_newl(t_list *list);
void				free_list(t_list **list, t_list *stash, char *buffer);
void				remain_chars(t_list **list);
void				concat_list(t_list **list, char *buffer);
void				create_list(t_list **list, int fd);
char				*get_line(t_list *buffer);

#endif
