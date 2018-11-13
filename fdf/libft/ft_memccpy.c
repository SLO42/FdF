/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 03:35:17 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/15 04:27:22 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t			pos;
	unsigned char	*ref;
	unsigned char	*surc;

	surc = (unsigned char*)src;
	ref = dst;
	pos = 0;
	while (pos < n)
	{
		ref[pos] = surc[pos];
		if (ref[pos] == (unsigned char)c)
			return (dst + pos + 1);
		pos++;
	}
	return (NULL);
}
