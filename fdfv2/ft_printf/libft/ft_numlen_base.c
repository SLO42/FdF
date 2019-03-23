/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:13:48 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 16:09:08 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen_base(int n, uint32_t base)
{
	int		len;
	long	nc;

	len = 0;
	nc = (long)n;
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
