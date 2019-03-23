/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_signed_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:45:25 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 12:24:00 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	spec_unsigned_int3(t_printf *prtf, va_list args)
{
	if (CMP(prtf->args->spec, 'x') || CMP(prtf->args->spec, 'X'))
		return (spec_unsigned_int_x_uint((prtf), args));
	else if (CMP(prtf->args->spec, 'o'))
		return (spec_unsigned_int_o_uint((prtf), args));
	else
		return (spec_unsigned_int_u_uint((prtf), args));
}

static void	spec_unsigned_int2(t_printf *prtf, va_list args)
{
	if (NOT1(prtf->args->stats->pf_ll))
	{
		if (CMP(prtf->args->spec, 'x') || CMP(prtf->args->spec, 'X'))
			return (spec_unsigned_int_x_ll((prtf), args));
		else if (CMP(prtf->args->spec, 'o'))
			return (spec_unsigned_int_o_ll((prtf), args));
		else
			return (spec_unsigned_int_u_ll((prtf), args));
	}
	else if (NOT1(prtf->args->stats->pf_l))
	{
		if (CMP(prtf->args->spec, 'x') || CMP(prtf->args->spec, 'X'))
			return (spec_unsigned_int_x_l((prtf), args));
		else if (CMP(prtf->args->spec, 'o'))
			return (spec_unsigned_int_o_l((prtf), args));
		else
			return (spec_unsigned_int_u_l((prtf), args));
	}
	else
		return (spec_unsigned_int3((prtf), args));
}

void		spec_unsigned_int(t_printf *prtf, va_list args)
{
	PPRE = PPRE == -1 ? 1 : PPRE;
	if (NOT1(prtf->args->stats->pf_hh))
	{
		if (CMP(prtf->args->spec, 'x') || CMP(prtf->args->spec, 'X'))
			return (spec_unsigned_int_x_hh((prtf), args));
		else if (CMP(prtf->args->spec, 'o'))
			return (spec_unsigned_int_o_hh((prtf), args));
		else
			return (spec_unsigned_int_u_hh((prtf), args));
	}
	else if (NOT1(prtf->args->stats->pf_h))
	{
		if (CMP(prtf->args->spec, 'x') || CMP(prtf->args->spec, 'X'))
			return (spec_unsigned_int_x_h((prtf), args));
		else if (CMP(prtf->args->spec, 'o'))
			return (spec_unsigned_int_o_h((prtf), args));
		else
			return (spec_unsigned_int_u_h((prtf), args));
	}
	else
		return (spec_unsigned_int2((prtf), args));
}

void		spec_signed_int(t_printf *prtf, va_list args)
{
	if (NOT1(prtf->args->stats->pf_hh))
		return (spec_signed_int_hh((prtf), args));
	else if (NOT1(prtf->args->stats->pf_h))
		return (spec_signed_int_h((prtf), args));
	else if (NOT1(prtf->args->stats->pf_ll))
		return (spec_signed_int_ll((prtf), args));
	else if (NOT1(prtf->args->stats->pf_l))
		return (spec_signed_int_l((prtf), args));
	else
		return (spec_signed_int_int((prtf), args));
}
