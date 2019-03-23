/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:04:59 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/20 13:41:21 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int			ft_llnumlen(long long nc)
{
	int	len;

	len = 0;
	while (nc != 0)
	{
		len++;
		nc /= 10;
	}
	return (len);
}

static long long	ft_llhelper(t_printf *prtf, long long n)
{
	if (n < 0)
	{
		n *= -1;
		prtf->args->flags->prepend_sign = 10;
		prtf->args->width--;
		prtf->args->stats->sign = 1;
	}
	return (n);
}

char				*ft_lltoa(t_printf *prtf, long long n)
{
	int		len;
	char	*nums;

	if (n == LLONG_MIN)
	{
		prtf->args->flags->prepend_sign = 10;
		prtf->args->stats->sign = 1;
		return (ft_strdup("9223372036854775808"));
	}
	if (n > 0 && prtf->args->flags->prepend_sign != 1)
		prtf->args->width--;
	n = ft_llhelper(prtf, n);
	len = ft_llnumlen(n);
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
