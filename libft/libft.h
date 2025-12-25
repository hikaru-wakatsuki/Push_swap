/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 03:42:20 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/25 07:05:42 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}					t_gnl;

typedef struct s_flags
{
	bool			minus;
	bool			zero;
	bool			hash;
	bool			plus;
	bool			space;
	int				width;
	bool			dot;
	int				precision;
}					t_flag;

// libft
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_gnl				*ft_lstnew(void *content);
void				ft_lstadd_front(t_gnl **lst, t_gnl *new);
int					ft_lstsize(t_gnl *lst);
t_gnl				*ft_lstlast(t_gnl *lst);
void				ft_lstadd_back(t_gnl **lst, t_gnl *new);
void				ft_lstdelone(t_gnl *lst, void (*del)(void *));
void				ft_lstclear(t_gnl **lst, void (*del)(void *));
void				ft_lstiter(t_gnl *lst, void (*f)(void *));
t_gnl				*ft_lstmap(t_gnl *lst, void *(*f)(void *),
						void (*del)(void *));
char				*ft_strndup(const char *s, size_t n);
size_t				count_words(char const *s, char const c);
// get_next_line_utils_bonus.c
char				*strjoin_and_free(char *s1, char *s2);
t_gnl				*get_node(int fd, t_gnl **head);
void				remove_node(int fd, t_gnl **head);
// get_next_line_bonus.c
char				*get_next_line(int fd);
// space_zero_print.c
bool				space_print(int flag_count, int *count);
bool				zero_print(int flag_count, int *count);
bool				space_print_malloc(int flag_count, int *count,
						char *buffer);
bool				zero_print_malloc(int flag_count, int *count, char *buffer);
// ft_specifier.c
bool				c_specifier(int content, int *count, t_flag *flag);
bool				s_specifier(char *content, int *count, t_flag *flag);
bool				p_specifier(void *content, int *count, t_flag *flag);
bool				di_specifier(int content, int *count, t_flag *flag);
bool				u_specifier(unsigned int content, int *count, t_flag *flag);
bool				x_specifier(unsigned int content, int *count, t_flag *flag);
bool				x_upper_specifier(unsigned int content, int *count,
						t_flag *flag);
bool				per_specifier(int *count);
// ft_specifier_helper.c
bool				x_width_print(unsigned int content, int *count,
						t_flag *flag, char *buffer);
bool				x_minus_print(unsigned int content, int *count,
						t_flag *flag, char *buffer);
int					flag_strlen(int content, char *buffer, t_flag *flag);
// ft_printf_helper
char				*itoa_base(uintptr_t n, char *base);
bool				flag_check(const char **format, t_flag *flag);
bool				is_flag_char(char const flag);
bool				is_specifier(char const c);
void				flag_initialization(t_flag *flag);
// ft_printf
int					ft_printf(const char *format, ...);
// ft_put_printf
bool				ft_putstr_printf(char *s, int *count);
bool				ft_putchar_printf(char c, int *count);
bool				ft_putnstr_printf(char *s, int *count, int n);

#endif
