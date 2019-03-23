/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 01:32:37 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/24 12:25:19 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf	*init(const char *format)
{
	t_printf *prtf;

	if (!(prtf = ft_memalloc(sizeof(t_printf))))
		return (NULL);
	if (ALLOC_LIST)
		return (NULL);
	if (ALLOC_ARGS)
		return (NULL);
	if (ALLOC_FLAGS || ALLOC_STATS)
		return (NULL);
	if ((ft_vector_init(prtf->output, 1)) == -1)
		return (NULL);
	prtf->len = 0;
	prtf->fmt = (char *)format;
	return (prtf);
}

int				ft_vfprintf(int fd, const char *format, va_list args)
{
	t_printf	*prtf;
	char		*tmp;
	int			ret;

	prtf = init(format);
	if (prtf == NULL)
		ft_exit(-1, prtf);
	while ((tmp = ft_strchr(prtf->fmt, '%')) != 0)
	{
		ft_vector_nappend((prtf->output), prtf->fmt, tmp - prtf->fmt);
		prtf->fmt = tmp;
		parse_f(args, prtf);
	}
	if (tmp)
		free(&tmp);
	if (*prtf->fmt != 0)
		ft_vector_appened((prtf->output), prtf->fmt);
	if (prtf->output->len)
		write(fd, CONTENT, CONTENT_SIZE);
	ret = prtf->output->len;
	ft_del_prtf(prtf);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = ft_vfprintf(1, format, args);
	va_end(args);
	return (ret);
}

void			printf_get_spec(t_printf *prtf, va_list args)
{
	int			i;
	static char values[12] = "%cspdiouxXfF";
	char		*spot;

	i = -1;
	spot = ft_strchr(values, *prtf->fmt);
	if (spot == '\0')
		ft_exit(-2, prtf);
	SPEC = *spot;
	prtf->fmt++;
	if (CMP(SPEC, '%'))
		spec_percentage((prtf));
	else if (CMP(SPEC, 'c'))
		spec_char((prtf), args);
	else if (CMP(SPEC, 's'))
		spec_string((prtf), args);
	else if (CMP(SPEC, 'd') || CMP(SPEC, 'i'))
		spec_signed_int((prtf), args);
	else if (CMP(SPEC, 'o') || CMP(SPEC, 'x')
		|| CMP(SPEC, 'X') || CMP(SPEC, 'u'))
		spec_unsigned_int((prtf), args);
	else if (CMP(SPEC, 'f') || CMP(SPEC, 'F'))
		spec_float(prtf, args);
	else if (CMP(SPEC, 'p'))
		spec_pointer(prtf, args);
}
