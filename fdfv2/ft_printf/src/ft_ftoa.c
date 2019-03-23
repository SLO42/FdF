/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 14:45:39 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/01 16:19:19 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isnan(long double num)
{
	union u_union	u;

	u.d = (double)num;
	if (u.ld == 0x7FF7FFFFFFFFFFFFLL)
		return (1);
	else
		return (0);
}

static int	isinf(long double num)
{
	union u_union	u;

	u.d = (double)num;
	if (u.ld == 0x7FF0000000000000LL)
		return (1);
	else if (u.ld == 0xFFF0000000000000LL)
		return (-1);
	else
		return (0);
}

static char	*edge_nan_inf(t_printf *prtf, int inf, long double num)
{
	if (inf)
	{
		if (inf == -1)
			prtf->args->stats->sign = 1;
		prtf->args->flags->prepend_sign = 10;
		if (SPEC == 'F')
			return (ft_strdup("INF"));
		else
			return (ft_strdup("inf"));
	}
	else if (isnan(num))
	{
		if (SPEC == 'F')
			return (ft_strdup("NAN"));
		else
			return (ft_strdup("nan"));
	}
	else
		return (NULL);
}

static char	*float_with_frac(t_printf *prtf, long double num)
{
	char		*whole;
	char		*num2;
	char		*tmp;
	char		*res;
	long double	frac;

	whole = ft_ulltoa_base(num, 10);
	prtf->args->pre++;
	prtf->args->width--;
	frac = ((num - (uintmax_t)(num)) * prtf_power(10, PPRE));
	frac = ((uintmax_t)(frac) % 10 >= 5) ? (frac / 10) + 1 : frac / 10;
	num2 = ft_ulltoa_base(frac, 10);
	if (ft_strlen(num2) < (size_t)(prtf->args->pre - 1))
	{
		DIFP = ((prtf->args->pre - 1) - ft_strlen(num2));
		if (DIFP > 0)
			num2 = fix_pre(num2, DIFP);
	}
	tmp = ft_strjoin(whole, ".");
	res = ft_strjoin(tmp, num2);
	free(whole);
	free(num2);
	free(tmp);
	return (res);
}

char		*handle_float(t_printf *prtf, va_list args)
{
	long double num;

	if (prtf->args->stats->pf__l != 1)
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	if (isnan(num) || isinf(num))
		return (edge_nan_inf(prtf, isinf(num), num));
	if ((double)0.0 > num)
	{
		prtf->args->stats->sign = 1;
		prtf->args->flags->prepend_sign = 2;
		num = -(num);
	}
	if (prtf->args->flags->prepend_sign != 1)
		prtf->args->width--;
	if (PPRE > 0)
		return (float_with_frac(prtf, num));
	else
		return (ft_ulltoa_base(num, 10));
}
