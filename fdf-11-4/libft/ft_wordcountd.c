/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcountd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:36:17 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/25 14:39:57 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcountd(char *str, char c)
{
	size_t count;

	if (*str != c && *str != 0)
		count = 1;
	else
		count = 0;
	while (*str != 0)
	{
		if (*str == c)
		{
			while (*str == c && *str != 0)
				str++;
			if (*str != c && *str != 0)
				count++;
		}
		else
			str++;
	}
	return (count);
}
