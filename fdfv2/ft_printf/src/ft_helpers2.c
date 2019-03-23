/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:30:09 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 15:50:32 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_prtf_add(char *str, size_t size, t_printf *prtf)
{
	if (PFLEN && SPEC != 'o' && SPEC != 'x' && SPEC != 'X' && SPEC != 'u'
		&& SPEC != 's')
	{
		PFLEN = 0;
		if (NOT1(PFLAGSIGN))
			prtf->args->stats->sign == 1 ? LSTADD("-", 1) : LSTADD("+", 1);
		else if (NOT1(PFLAGSPACE))
			LSTADD(" ", 1);
	}
	LSTADD(str, size);
}

static void	hex_helper_alt_fixer(t_printf *prtf, int or)
{
	if (or == 1)
	{
		prtf->args->flags->alt_form != 1 ? create_width(prtf, 2, 2) : 0;
		prtf->args->flags->alt_form = prtf->args->flags->alt_form != 1 ? 1 : 1;
	}
	else if (or == 2)
	{
		prtf->args->flags->prepend_sign = 10;
		prtf->args->width--;
		prtf->args->stats->sign = 1;
	}
	else
		return ;
}

static void	hex_helper_catch(t_printf *prtf, size_t size, int or)
{
	if (or == 1)
	{
		create_width((prtf), size, 1);
		hex_helper_alt_fixer(prtf, 1);
	}
	else if (or == 2)
	{
		hex_helper_alt_fixer(prtf, 1);
		create_width((prtf), size, 0);
	}
	else if (or == 3)
	{
		create_width(prtf, size, 0);
		hex_helper_alt_fixer(prtf, 1);
	}
}

void		spec_hex_helper(t_printf *prtf, char *num)
{
	if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
	{
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
		hex_helper_catch(prtf, DIFP, 1);
	}
	else if ((DIFW = DIFSZ(ft_strlen(num), PWIDTH)) > 0)
	{
		if (prtf->args->flags->pad_zeros != 1)
			hex_helper_catch(prtf, DIFW, 2);
		else
			hex_helper_catch(prtf, DIFW, 3);
	}
	else
		hex_helper_alt_fixer(prtf, 1);
	if (prtf->args->pre != 0 && ((num) || num[0] != '0'))
		IFHEX(num, ft_strlen(num));
	else
		free(num);
}

char		*ft_printf_itoa(t_printf *prtf, int n)
{
	int		len;
	char	*nums;

	if (n == -2147483648)
	{
		prtf->args->flags->prepend_sign = 10;
		prtf->args->stats->sign = 1;
		return (ft_strdup("2147483648"));
	}
	if (n > 0 && prtf->args->flags->prepend_sign != 1)
		prtf->args->width--;
	if (n < 0 && (n *= -1) > 0)
		hex_helper_alt_fixer(prtf, 2);
	len = ft_numlen(n);
	if (!(nums = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nums[len] = '\0';
	while (len--)
	{
		nums[len] = (n % 10) + 48;
		n /= 10;
	}
	return (nums);
}
