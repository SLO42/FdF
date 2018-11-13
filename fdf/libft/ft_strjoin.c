/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 02:55:52 by saolivei          #+#    #+#             */
/*   Updated: 2018/08/14 16:15:14 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	pos;
	char			*js;

	i = 0;
	pos = 0;
	if (!s1 || !s2)
		return (0);
	if (!(js = ft_strnew((ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1)))
		return (NULL);
	while (s1[i] != '\0')
		js[pos++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		js[pos++] = s2[i++];
	js[pos] = '\0';
	return (js);
}
