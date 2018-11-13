/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:47:49 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/16 14:55:50 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char	*refd;
	unsigned char	*refs;
	size_t			pos;

	refd = dst;
	refs = (unsigned char*)src;
	pos = 0;
	if (refs < refd)
	{
		while (len-- > 0)
			refd[len] = refs[len];
	}
	else
		ft_memcpy(refd, refs, len);
	return (dst);
}
