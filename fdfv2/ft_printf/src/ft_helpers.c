/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:47:20 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 15:50:30 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		create_space_or_sign(t_printf *prtf)
{
	prtf->args->stats->l = 0;
	if (NOT1(PFLAGSIGN))
		prtf->args->stats->sign == 1 ? LSTADD("-", 1) : LSTADD("+", 1);
	else if (NOT1(PFLAGSPACE) && PPRE > PWIDTH)
		return (LSTADD(" ", 1));
}

/*
** or = override #:
** when or = 7, we want to print spaces even if the pad_zeros flag is toggled.
** when or = 2, we want to print 0x for the start of a pointer.
** when or = 1, we want to print 0's even if the pad_zeros flag is not toggled.
** when or = 0, we want to be at the whim of the user... DANGER
*/

void			create_width(t_printf *prtf, int amount, int or)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(amount);
	if (or == 2)
	{
		tmp[0] = '0';
		tmp[1] = 'x';
		SPEC == 'X' ? ft_vector_appened((prtf->output), ft_strupper(tmp))
			: ft_vector_appened((prtf->output), tmp);
	}
	else if ((NOT1(prtf->args->flags->pad_zeros) && or != 7) || or == 1)
	{
		while (amount--)
			tmp[i++] = '0';
		ft_vector_appened((prtf->output), tmp);
	}
	else
	{
		while (amount--)
			tmp[i++] = ' ';
		ft_vector_appened((prtf->output), tmp);
	}
	free(tmp);
}

void			first_width(t_printf *prtf, int amount, int or)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(amount);
	if ((NOT1(prtf->args->flags->pad_zeros) && or != 7) || or == 1)
	{
		while (amount--)
			tmp[i++] = '0';
		if (prtf->args->stats->l)
			create_space_or_sign((prtf));
		ft_vector_appened((prtf->output), tmp);
	}
	else
	{
		while (amount--)
			tmp[i++] = ' ';
		ft_vector_appened((prtf->output), tmp);
		if (prtf->args->stats->l)
			create_space_or_sign((prtf));
	}
	ft_strdel(&tmp);
}

int				if_alt(t_printf *prtf, int size, char *num)
{
	if (NOT1(prtf->args->flags->alt_form))
	{
		if (SPEC == 'o')
		{
			if (PPRE == 0 && size == 1)
			{
				ft_prtf_add("0", 1, prtf);
				return (1);
			}
			else if (PPRE < size && num[0] != '0')
			{
				PPRE = size + 1;
				return (PPRE);
			}
		}
	}
	return (1);
}

int				ft_nou_del(char **as)
{
	if (!as)
		return (0);
	free(*as);
	*as = NULL;
	return (1);
}
