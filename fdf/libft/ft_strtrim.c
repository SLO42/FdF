/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:19:24 by saolivei          #+#    #+#             */
/*   Updated: 2018/08/14 16:36:03 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	pos;

	pos = 0;
	if (!s)
		return (0);
	while (s[pos] == ' ' || s[pos] == '\n' || s[pos] == '\t')
		pos++;
	if (s[pos] == 0)
		return (ft_strdup(s + pos));
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len > 0)
		len--;
	return (ft_strsub(s, pos, len - pos + 1));
}
