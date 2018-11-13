/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 22:43:43 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/18 01:17:22 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t			pos;
	unsigned char	*refs1;
	unsigned char	*refs2;

	pos = 0;
	refs1 = (unsigned char*)s1;
	refs2 = (unsigned char*)s2;
	while (pos < n)
	{
		if (refs1[pos] != refs2[pos])
			return (refs1[pos] - refs2[pos]);
		pos++;
	}
	return (0);
}
