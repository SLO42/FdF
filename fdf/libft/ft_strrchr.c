/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:24:43 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/13 16:35:01 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long pos;

	pos = (long)ft_strlen((char*)s);
	while (pos >= 0)
	{
		if (s[pos] == c)
			return ((char*)&s[pos]);
		pos--;
	}
	return (NULL);
}
