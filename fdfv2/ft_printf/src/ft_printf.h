/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:57 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/20 13:43:09 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include "../libft/libft.h"
# define NOT1(a) (a != 1)
# define CMP(x, y) (x == y)
# define PFLAGSPACE prtf->args->flags->prepend_space
# define PFLAGSIGN prtf->args->flags->prepend_sign
# define PFLEN prtf->args->stats->l
# define DIFW prtf->args->stats->difw
# define DIFP prtf->args->stats->difp
# define PWIDTH prtf->args->width
# define PPRE prtf->args->pre
# define CONTENT prtf->output->data
# define CONTENT_SIZE prtf->output->len
# define ULL unsigned long long
# define SPEC prtf->args->spec
# define ALLOC_FLAGS !(prtf->args->flags = ft_memalloc(sizeof(t_printf_flags)))
# define ALLOC_STATS !(prtf->args->stats = ft_memalloc(sizeof(t_printf_stats)))
# define ALLOC_LIST !(prtf->output = ft_memalloc(sizeof(t_vector)))
# define ALLOC_ARGS !(prtf->args = ft_memalloc(sizeof(t_printf_args)))
# define LSTADD(c, s) (ft_vector_nappend((prtf->output), c, s))
# define LSTADD2(p, c)(ft_vector_appened(p, c))
# define PRECK(c, s) (precheck(c, s, prtf))
# define IFHEX(c, s) (SPEC == 'x' ? PRECK(ft_strlower(c), s) : PRECK(c, s))
# define ADDHIGHHEX ft_prtf_add("0X", 2, prtf)
# define ADDLOWHEX ft_prtf_add("0x", 2, prtf)
# define ALTHEX SPEC == 'x' ? ADDLOWHEX : ADDHIGHHEX
# define IFALT(s) (if_alt(prtf, s, num))
# define ADDLST(c, s) (ft_prtf_add(c, s, prtf))
# define ULL_FLOAT_TO_BASE ft_ulltoa_base(ft_power(tmpp, (num - (int)num)), 10)
# define SPEC_CHECK2(a, b, c, d)(SPEC_CHECK(a,b) && SPEC_CHECK(c,d))
# define SPEC_CHECK(a, b)(prtf->args->pre != a && prtf->args->pre != b)
# define CHECK_GR5(s, i)(s[i] == '9' && s[i + 1] >= '5' && s[i + 1] <= '9')
# define ROUND_CHECK(a, b, c)((b != NULL) ? ft_strjoin(c, b) : ft_strdup(a))
# define LST_ADD_0(p)(ft_vector_appened_null(p))
# define TERN_IFNOLEN_1(l, f) ((l == 0 && f == 0) ? 1 : l)
# define CHECK_NULL_APPENED(c, p)(c[0] == 0 ? LST_ADD_0(p) : LSTADD2(p, c))
# define DIFSZ(a, b) (((size_t)a < (size_t)b) ? b - a : 0)

typedef	struct		s_printf_flags
{
	short			f;
	short			left_just;
	short			prepend_sign;
	short			prepend_space;
	short			alt_form;
	short			pad_zeros;
}					t_printf_flags;

typedef	struct		s_printf_stats
{
	short			l;
	short			pf_hh;
	short			pf_h;
	short			pf_l;
	short			pf__l;
	short			pf_ll;
	int				difw;
	int				difp;
	short			sign;
}					t_printf_stats;

typedef	struct		s_printf_args
{
	t_printf_flags	*flags;
	t_printf_stats	*stats;
	int				width;
	int				pre;
	char			spec;
}					t_printf_args;

typedef	struct		s_printf
{
	t_vector		*output;
	t_printf_args	*args;
	char			*fmt;
	size_t			len;
}					t_printf;

union				u_union
{
	ULL				ld;
	double			d;
}					u;
/*
** char	*ft_power(int power, long double dare);
** char	*ft_round(char *num);
** char	*ft_ftoa(long double num, t_printf *prtf);
** NOT CORRECT FORMAT : CHANGED TO one time DOUBLE EVAL
** int  ft_size_dif(size_t size, int width);
** RENDEDRED USESLESS WITH "DIFSZ" MACRO
*/
int					ft_printf(char const *format, ...);
int					ft_vfprintf(int fd, const char *format, va_list args);
void				printf_get_spec(t_printf *prtf, va_list args);
void				free_it_all(t_printf *prtf);
void				ft_exit(short num, t_printf *prtf);
void				ft_del_prtf(t_printf *prtf);
void				ft_vector_appened_null(t_vector *vector);
void				parse_f(va_list args, t_printf *prtf);
int					if_alt(t_printf *prtf, int size, char *num);
int					ft_chr_in_str(const char *t, int s, char c, t_printf *p);
int					ft_nou_del(char **as);
char				*ft_printf_itoa(t_printf *prtf, int n);
char				*ft_lltoa(t_printf *prtf, long long n);
int					ft_signedchar(int num);
/*
** Append the result to the vector | Checking before adding.
*/
void				add_then_delete(char *str, size_t size, t_printf *prtf);
void				precheck(char *str, size_t size, t_printf *prtf);
void				ft_prtf_add(char *str, size_t size, t_printf *prtf);
/*
** CLEAN
*/
void				clean_parse(t_printf *prtf);
/*
** default create elem for space/0/0x
*/
void				create_width(t_printf *prtf, int amount, int or);
/*
** used for checking if is altform or any missing info.
*/
void				first_width(t_printf *prtf, int amount, int or);
/*
** floats
*/
void				spec_float(t_printf *prtf, va_list args);
void				spec_float__l(t_printf *prtf, va_list args);
void				spec_float_float(t_printf *prtf, va_list args);
void				spec_float_l(t_printf *prtf, va_list args);
char				*handle_float(t_printf *prtf, va_list args);
uintmax_t			prtf_power(uintmax_t nb, uintmax_t power);
char				*fix_pre(char *num, size_t dif);
/*
** spec precentage
*/
void				spec_percentage(t_printf *prtf);
/*
** char and char*
*/
void				spec_char(t_printf *prtf, va_list args);
void				spec_string(t_printf *prtf, va_list args);
/*
** signed int
*/
void				spec_signed_helper(t_printf *prtf, char *num, size_t len);
void				spec_signed_int(t_printf *prtf, va_list args);
void				spec_signed_int_int(t_printf *prtf, va_list args);
void				spec_signed_int_l(t_printf *prtf, va_list args);
void				spec_signed_int_ll(t_printf *prtf, va_list args);
void				spec_signed_int_h(t_printf *prtf, va_list args);
void				spec_signed_int_hh(t_printf *prtf, va_list args);
/*
** unsigned int
*/
void				spec_unsigned_int(t_printf *prtf, va_list args);
void				spec_unsigned_int_u_uint(t_printf *prtf, va_list args);
void				spec_unsigned_int_u_h(t_printf *prtf, va_list args);
void				spec_unsigned_int_u_hh(t_printf *prtf, va_list args);
void				spec_unsigned_int_u_l(t_printf *prtf, va_list args);
void				spec_unsigned_int_u_ll(t_printf *prtf, va_list args);
/*
** unsigned int -> hex
*/
void				spec_hex_helper(t_printf *prtf, char *num);
void				spec_unsigned_int_x_uint(t_printf *prtf, va_list args);
void				spec_unsigned_int_x_h(t_printf *prtf, va_list args);
void				spec_unsigned_int_x_hh(t_printf *prtf, va_list args);
void				spec_unsigned_int_x_l(t_printf *prtf, va_list args);
void				spec_unsigned_int_x_ll(t_printf *prtf, va_list args);
/*
** unsigned int -> octet
*/
void				spec_octal(t_printf *prtf, va_list args);
void				spec_unsigned_int_o_uint(t_printf *prtf, va_list args);
void				spec_unsigned_int_o_h(t_printf *prtf, va_list args);
void				spec_unsigned_int_o_hh(t_printf *prtf, va_list args);
void				spec_unsigned_int_o_l(t_printf *prtf, va_list args);
void				spec_unsigned_int_o_ll(t_printf *prtf, va_list args);
/*
** void* -> address
*/
void				spec_pointer(t_printf *prtf, va_list args);
/*
** creating padding and 0x
*/
void				create_width(t_printf *prtf, int amount, int or);

#endif
