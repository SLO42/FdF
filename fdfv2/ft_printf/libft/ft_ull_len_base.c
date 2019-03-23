/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:31:25 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 16:19:06 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ull_len_base(unsigned long long n, uint32_t base)
{
	int					len;
	unsigned long long	nc;

	len = 1;
	nc = n;
	while (nc != 0)
	{
		len++;
		nc /= base;
	}
	return (len);
}
