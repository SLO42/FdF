/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:33:05 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/13 17:37:05 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t pos;

	pos = 0;
	if (n == 0)
		return (0);
	while ((s1[pos] == s2[pos] && (s1[pos] != 0
		|| s2[pos] != 0)) && pos < n - 1)
		pos++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}
