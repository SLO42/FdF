/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 17:06:44 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/13 17:12:06 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int num;

	num = 0;
	while (s1[num] == s2[num] && (s1[num] || s2[num]))
		num++;
	return ((unsigned char)s1[num] - (unsigned char)s2[num]);
}
