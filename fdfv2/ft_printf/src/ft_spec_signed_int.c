/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_signed_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:59:15 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/20 19:43:37 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			spec_signed_int_l(t_printf *prtf, va_list args)
{
	char	*num;
	size_t	len;

	num = ft_lltoa(prtf, (long)va_arg(args, long));
	len = ft_strlen(num);
	if (PPRE == 0 && (!(num) || *num == 0))
		return ;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(len, PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck((num), len, prtf);
		if ((DIFW = DIFSZ((len + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num, len);
}

void			spec_signed_int_ll(t_printf *prtf, va_list args)
{
	char	*num;
	size_t	len;

	num = ft_lltoa(prtf, (long long)va_arg(args, long long));
	len = ft_strlen(num);
	if (PPRE == 0 && (!(num) || *num == 0))
		return ;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(len, PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck((num), len, prtf);
		if ((DIFW = DIFSZ((len + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num, len);
}

void			spec_signed_int_int(t_printf *prtf, va_list args)
{
	char	*num;
	size_t	len;

	num = ft_printf_itoa(prtf, (int)va_arg(args, signed int));
	if (prtf->args->pre == 0 && (!(num) || num[0] == '0'))
		num[0] = '\0';
	len = ft_strlen(num);
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(len, PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		DIFP = DIFP < 0 ? 0 : DIFP;
		precheck((num), len, prtf);
		if ((DIFW = DIFSZ((len + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num, len);
}

void			spec_signed_int_h(t_printf *prtf, va_list args)
{
	char	*num;
	size_t	len;

	num = ft_printf_itoa(prtf, (short)va_arg(args, signed int));
	if (prtf->args->pre == 0 && (!(num) || num[0] == '0'))
		num[0] = '\0';
	len = ft_strlen(num);
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(len, PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		DIFP = DIFP < 0 ? 0 : DIFP;
		precheck((num), len, prtf);
		if ((DIFW = DIFSZ((len + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num, len);
}

void			spec_signed_int_hh(t_printf *prtf, va_list args)
{
	char	*num;
	size_t	len;

	num = ft_printf_itoa(prtf, (signed char)va_arg(args, signed int));
	if (prtf->args->pre == 0 && (!(num) || num[0] == '0'))
		num[0] = '\0';
	len = ft_strlen(num);
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(len, PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		DIFP = DIFP < 0 ? 0 : DIFP;
		precheck((num), len, prtf);
		if ((DIFW = DIFSZ((len + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num, len);
}
