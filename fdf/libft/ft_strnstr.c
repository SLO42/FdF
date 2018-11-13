/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:55:45 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/13 17:03:47 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] && (size_t)(i) < loc)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < loc && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
