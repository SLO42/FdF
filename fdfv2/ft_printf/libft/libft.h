/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:57:37 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/22 14:58:09 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1000
# define FD_SIZE 4096
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct		s_set
{
	long double		x;
	long double		y;
	long double		z;
}					t_set;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vector
{
	size_t			len;
	size_t			cap;
	char			*data;
}					t_vector;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isspace(int c);
int					ft_numlen(int n);
int					ft_numlen_base(int n, uint32_t base);
int					ft_ull_len_base(unsigned long long n, uint32_t base);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
int					ft_atoi(char const *str);
int					get_next_line(const int fd, char **line);
int					ft_rand(int max);
int					ft_vector_init(t_vector *vector, size_t init_cap);
int					ft_lllen_base(long long n, uint32_t base);
int					ft_ischar(int a, int b);
long				ft_atoi_base(const char *str, int str_base);
short				ft_atosh(char const *str);
char				*ft_strlower(char *str);
char				*ft_strupper(char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hs, const char *nd, size_t loc);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, uint32_t base);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(long n, uint32_t base);
char				*ft_ulltoa_base(uintmax_t n, uint32_t base);
char				**ft_strsplit(char const *s, char c);
char				*ft_create_hex(void);
char				**ft_array(int num, ...);
char				*ft_string(int num, ...);
char				*ft_stringd(int num, int del, ...);

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, char const *src, size_t dstsize);
size_t				ft_wordcountd(char *str, char c);
size_t				ft_lstlen(t_list *start_lst);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);
void				*ft_memchr(void const *s, int c, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_recalloc(char *ptr, size_t src_size, size_t new_size);
void				ft_vector_free(t_vector *vector);
void				ft_vector_nappend(t_vector *vector, char *n_d, size_t n);
void				ft_vector_resize(t_vector *vector, size_t min);
void				ft_vector_appened(t_vector *vector, char *newdata);

#endif
