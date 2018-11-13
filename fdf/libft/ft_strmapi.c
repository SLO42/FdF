/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 01:55:33 by saolivei          #+#    #+#             */
/*   Updated: 2018/08/14 16:35:32 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*end;
	unsigned int	pos;

	pos = 0;
	if (!f || !s)
		return (0);
	if (!(end = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	while (s[pos] != '\0')
	{
		end[pos] = f(pos, s[pos]);
		pos++;
	}
	return (end);
}
