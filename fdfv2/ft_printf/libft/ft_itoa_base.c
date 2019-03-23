/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:48:48 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 16:30:06 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char	*ft_itoaexc(uint32_t base)
{
	long		num;
	int			i;
	const char	tab[16] = "0123456789ABCDEF";
	char		*ret;

	i = 0;
	num = INT_MIN;
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

char		*ft_itoa_base(int n, uint32_t base)
{
	int				len;
	char			*nums;
	const char		tab[16] = "0123456789ABCDEF";

	if (base < 2 || base > 16)
		return (NULL);
	if (n == -2147483648)
		return (ft_itoaexc(base));
	if (base == 10)
		return (ft_itoa(n));
	len = ft_numlen_base(n, base);
	if (!(nums = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		nums[0] = '-';
	}
	while (--len >= 0)
	{
		nums[len] = tab[(n % base)];
		n /= base;
	}
	return (nums);
}
