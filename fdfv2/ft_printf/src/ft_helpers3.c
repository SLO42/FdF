/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:41:31 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 15:50:35 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		spec_signed_helper(t_printf *prtf, char *num, size_t len)
{
	if ((DIFP = DIFSZ(len, PPRE)) > 0)
	{
		if ((DIFW = DIFSZ((len + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
		first_width((prtf), DIFP, 1);
	}
	else if (len == (size_t)PPRE && (size_t)PWIDTH > len)
		create_width(prtf, PWIDTH - len, 7);
	else if ((DIFW = DIFSZ(len, PWIDTH)) > 0)
		first_width((prtf), DIFW, 0);
	precheck((num), len, prtf);
}

void		add_then_delete(char *str, size_t size, t_printf *prtf)
{
	ft_prtf_add(str, size, prtf);
	free(str);
}

void		precheck(char *str, size_t size, t_printf *prtf)
{
	int i;

	i = 0;
	if (NOT1(prtf->args->flags->alt_form) && SPEC_CHECK2('i', 'o', 'u', 'd'))
	{
		if ((SPEC == 'f' || SPEC == 'F'))
		{
			while (*str)
			{
				if (*str == '.')
				{
					add_then_delete(str, size, prtf);
					return ;
				}
				str++;
				i++;
			}
			str = str - i;
			add_then_delete(str, size, prtf);
			LSTADD(".", 1);
			return ;
		}
	}
	add_then_delete(str, size, prtf);
}

uintmax_t	prtf_power(uintmax_t nb, uintmax_t power)
{
	uintmax_t	i;

	if (power == 0)
		return (1);
	if (power % 2 == 0)
	{
		i = prtf_power(nb, power / 2);
		return (i * i);
	}
	else
		return (nb * prtf_power(nb, power - 1));
}

char		*fix_pre(char *num, size_t dif)
{
	char	*tmp;
	char	*res;
	size_t	i;

	i = -1;
	tmp = ft_strnew(dif);
	while (++i < dif)
		tmp[i] = '0';
	res = ft_strjoin(tmp, num);
	free(num);
	free(tmp);
	return (res);
}
