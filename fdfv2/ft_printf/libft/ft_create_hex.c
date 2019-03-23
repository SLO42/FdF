/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 23:18:51 by saolivei          #+#    #+#             */
/*   Updated: 2018/10/20 23:18:53 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_create_hex(void)
{
	int		p1;
	int		randy;
	char	rgb[7];
	char	*string;

	p1 = 0;
	ft_bzero(rgb, 7);
	while (p1 != 6)
	{
		if ((randy = (ft_rand(15)) < 9))
			rgb[p1] = ft_rand(9) + 48;
		else
			rgb[p1] = ft_rand(5) + 65;
		p1++;
	}
	string = ft_strdup(rgb);
	return (string);
}
