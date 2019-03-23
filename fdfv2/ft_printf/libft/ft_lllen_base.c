/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:06:17 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 15:37:46 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lllen_base(long long n, uint32_t base)
{
	int			len;
	long long	nc;

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
