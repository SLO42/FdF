/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:53:27 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/20 16:11:36 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t lens1;
	size_t pos;

	pos = 0;
	lens1 = ft_strlen(s1);
	while (pos < n && s2[pos])
	{
		s1[lens1] = s2[pos];
		pos++;
		lens1++;
	}
	s1[lens1] = '\0';
	return (s1);
}
