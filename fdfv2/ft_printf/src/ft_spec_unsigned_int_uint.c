/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_unsigned_int_uint.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:48:42 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/21 11:30:41 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_unsigned_int_u_uint(t_printf *prtf, va_list args)
{
	char	*num;

	num = ft_lltoa(prtf, (unsigned int)va_arg(args, unsigned int));
	if (prtf->args->pre == 0 && (!(num) || num[0] == '0'))
		num[0] = '\0';
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck(num, ft_strlen(num), prtf);
		if ((DIFW = DIFSZ(ft_strlen(num) + DIFP, PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
		{
			if ((DIFW = DIFSZ(ft_strlen(num) + DIFP, PWIDTH)) > 0)
				create_width((prtf), DIFW, 0);
			create_width((prtf), DIFP, 1);
		}
		else if ((DIFW = DIFSZ(ft_strlen(num), PWIDTH)) > 0)
			create_width((prtf), DIFW, 0);
		precheck(num, ft_strlen(num), prtf);
	}
}

void	spec_unsigned_int_x_uint(t_printf *prtf, va_list args)
{
	char	*num;

	num = ft_ulltoa_base((unsigned int)va_arg(args, unsigned int), 16);
	if (prtf->args->pre == 0 && (!(num) || num[0] == '0'))
		num[0] = '\0';
	if (num[0] == '\0')
		prtf->args->flags->alt_form = 1;
	PWIDTH = prtf->args->flags->alt_form != 1 ? PWIDTH - 2 : PWIDTH;
	if (num[0] == '0')
		prtf->args->flags->alt_form = 1;
	if (prtf->args->flags->left_just != 1)
	{
		prtf->args->flags->alt_form != 1 ? create_width(prtf, 2, 2) : 0;
		prtf->args->flags->alt_form = prtf->args->flags->alt_form != 1 ? 1 : 1;
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			create_width((prtf), DIFP, 1);
		if (prtf->args->pre != 0 && ((num) || num[0] != '0'))
			IFHEX(num, ft_strlen(num));
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_hex_helper(prtf, num);
}

void	spec_unsigned_int_o_uint(t_printf *prtf, va_list args)
{
	char	*num;

	num = ft_ulltoa_base((unsigned int)va_arg(args, unsigned int), 8);
	if (if_alt(prtf, (ft_strlen(num) > 0) ? ft_strlen(num) : 1, num))
		num[0] = num[0] == '0' ? '\0' : num[0];
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			create_width((prtf), DIFP, 1);
		PRECK(num, ft_strlen(num));
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
		{
			if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
				create_width((prtf), DIFW, 0);
			create_width((prtf), DIFP, 1);
		}
		else if ((DIFW = DIFSZ(ft_strlen(num), PWIDTH)) > 0)
			create_width((prtf), DIFW, 0);
		PRECK(num, ft_strlen(num));
	}
}
