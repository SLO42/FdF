/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:36:11 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 16:15:35 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_percentage(t_printf *prtf)
{
	if (prtf->args->width - 1 > 0)
	{
		if (NOT1(prtf->args->flags->left_just))
		{
			ft_vector_nappend((prtf->output), "%", 1);
			create_width(prtf, prtf->args->width - 1, 7);
		}
		else
		{
			create_width(prtf, prtf->args->width - 1, 0);
			ft_vector_nappend((prtf->output), "%", 1);
		}
	}
	else
		ft_vector_nappend((prtf->output), "%", 1);
}

void	ft_vector_appened_null(t_vector *vector)
{
	size_t	nd_len;

	nd_len = 1;
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, "\0", nd_len);
	vector->len += nd_len;
}

void	spec_char(t_printf *prtf, va_list args)
{
	int		dif;
	char	*c;

	if (!(c = ft_strnew(2)))
		ft_exit(-1, prtf);
	c[0] = (char)va_arg(args, int);
	dif = DIFSZ(1, PWIDTH);
	if (dif)
	{
		if (NOT1(prtf->args->flags->left_just))
		{
			CHECK_NULL_APPENED(c, prtf->output);
			create_width((prtf), dif, 7);
		}
		else
		{
			create_width((prtf), dif, 0);
			CHECK_NULL_APPENED(c, prtf->output);
		}
	}
	else
		CHECK_NULL_APPENED(c, prtf->output);
	if (c)
		free(c);
}

char	*check_and_modify(t_printf *prtf, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup(str);
	tmp2 = NULL;
	prtf->args->stats->pf__l = tmp != tmp2 ? 1 : 0;
	if (PPRE != -1 && (int)ft_strlen(tmp) > PPRE)
		tmp2 = ft_strsub(tmp, 0, PPRE);
	else
		return (tmp);
	free(tmp);
	return (tmp2);
}

void	spec_string(t_printf *prtf, va_list args)
{
	char	*tmp;
	int		dif;
	int		flag;

	tmp = (char *)va_arg(args, char *);
	tmp = check_and_modify(prtf, tmp);
	flag = prtf->args->stats->pf__l;
	if ((dif = DIFSZ(ft_strlen(tmp), PWIDTH)) > 0)
	{
		if (NOT1(prtf->args->flags->left_just))
		{
			precheck(tmp, (TERN_IFNOLEN_1(ft_strlen(tmp), flag)), prtf);
			create_width((prtf), dif, 7);
		}
		else
		{
			create_width((prtf), dif, 0);
			precheck(tmp, (TERN_IFNOLEN_1(ft_strlen(tmp), flag)), prtf);
		}
	}
	else
		precheck(tmp, (TERN_IFNOLEN_1(ft_strlen(tmp), flag)), prtf);
}
