/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:48:48 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 16:06:17 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_longlen_base(long n, uint32_t base)
{
	int		len;
	long	nc;

	len = 0;
	nc = n;
	if (nc < 0)
	{
		len++;
		nc = -nc;
	}
	while (nc != 0)
	{
		len++;
		nc /= base;
	}
	return (len);
}

char		*ft_ltoa_base(long n, uint32_t base)
{
	int			len;
	char		*nums;
	const char	tab[16] = "0123456789ABCDEF";

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10)
		return (ft_itoa(n));
	len = ft_longlen_base(n, base);
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
