/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:12:14 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/16 15:28:28 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	*ref;
	size_t			pos;

	ref = (unsigned char*)s;
	pos = 0;
	while (pos < n)
	{
		if (ref[pos] == (unsigned char)c)
			return ((void*)s + pos);
		pos++;
	}
	return (NULL);
}
