/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:26:31 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/14 20:28:41 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char *refd;
	unsigned char *refs;

	refd = (unsigned char*)dst;
	refs = (unsigned char*)src;
	while (n-- != 0)
		*refd++ = *refs++;
	return (dst);
}
