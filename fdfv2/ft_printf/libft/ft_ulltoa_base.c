/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:48:48 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 12:21:40 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char		*ft_ulltoaexc(uint32_t base)
{
	long		num;
	int			i;
	const char	tab[16] = "0123456789ABCDEF";
	char		*ret;

	i = 0;
	num = ULLONG_MAX;
	while (num > 0)
	{
		i++;
		num /= base;
	}
	if (!(ret = ft_strnew(i)))
		return (NULL);
	while (--i)
		ret[i] = tab[base - 1];
	return (ret);
}

char			*ft_ulltoa_base(uintmax_t n, uint32_t base)
{
	int							len;
	char						*nums;
	const char					tab[16] = "0123456789ABCDEF";
	const uintmax_t				max = 18446744073709551615ULL;
	uintmax_t					num;

	num = n;
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_ull_len_base(num, base);
	if (num == max)
		return (ft_ulltoaexc(base));
	if (!(nums = ft_strnew(len)))
		return (NULL);
	if (len > 1)
		while (--len - 1 >= 0)
		{
			nums[len - 1] = tab[(num % base)];
			num /= base;
		}
	else
		nums[0] = tab[(num % base)];
	return (nums);
}
