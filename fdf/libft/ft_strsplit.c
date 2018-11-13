/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:06:40 by saolivei          #+#    #+#             */
/*   Updated: 2018/08/14 16:45:05 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t		count;
	size_t		ap;
	size_t		pos;
	size_t		start;
	char		**wlist;

	if (!s || !c)
		return (0);
	count = ft_wordcountd((char *)s, c);
	ap = -1;
	pos = 0;
	if (!(wlist = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (++ap < count && s[pos] != 0)
	{
		while (s[pos] == c)
			pos++;
		start = pos;
		while (s[pos] != c && s[pos] != 0)
			pos++;
		wlist[ap] = ft_strsub(s, start, (pos - start));
	}
	wlist[ap] = NULL;
	return (wlist);
}
