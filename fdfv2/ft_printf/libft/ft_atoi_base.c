/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:57:25 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/22 12:00:22 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_within(char c, int str_base)
{
	int			i;
	const char	tab[16] = "0123456789abcdef";

	i = 0;
	while (i != str_base)
	{
		if (c == tab[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	add_mult(int ret, int value_to_add)
{
	ret += value_to_add;
	return (ret);
}

static void	do_loop(char c, int len_i, long *ret, int str_base)
{
	int		vta;

	if (str_base > 10 && c >= 65 && c <= 70)
	{
		if ((vta = is_within(c + 32, str_base)) != -1)
			*ret = add_mult(*ret, vta << (4 * (len_i)));
	}
	else if ((vta = is_within(c, str_base)) != -1)
		*ret = add_mult(*ret, vta << (4 * (len_i)));
}

long		ft_atoi_base(const char *str, int str_base)
{
	int			i;
	long		ret;
	int			len;

	i = 0;
	ret = 0;
	while (str[i] != 0)
		i++;
	i--;
	len = i;
	while (i != 0)
	{
		do_loop(str[i], len - i, &ret, str_base);
		i--;
	}
	if (str[0] == '-')
		ret *= -1;
	else
		do_loop(str[i], len - i, &ret, str_base);
	return (ret);
}
