/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:52:11 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/20 18:03:45 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t len;
	size_t pos;

	pos = 0;
	len = 0;
	while (dst[len] && len < dstsize)
		len++;
	while ((len + pos + 1) < dstsize && src[pos] != '\0')
	{
		dst[len + pos] = src[pos];
		pos++;
	}
	if (len != dstsize)
		dst[len + pos] = '\0';
	return (len + ft_strlen(src));
}
