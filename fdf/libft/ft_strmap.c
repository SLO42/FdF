/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 01:46:22 by saolivei          #+#    #+#             */
/*   Updated: 2018/08/14 16:35:23 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*end;
	size_t	pos;

	pos = 0;
	if (!s || !f)
		return (0);
	if (!(end = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	while (s[pos] != '\0')
	{
		end[pos] = f(s[pos]);
		pos++;
	}
	return (end);
}
