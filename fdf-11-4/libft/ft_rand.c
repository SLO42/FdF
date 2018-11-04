/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 23:18:38 by saolivei          #+#    #+#             */
/*   Updated: 2018/10/20 23:18:41 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	ft_rand(int max)
{
	char	num[9];
	int		n;
	int		i;
	int		r;

	i = 0;
	r = 0;
	n = open("/dev/random", O_RDONLY);
	read(n, num, 9);
	close(n);
	while (i < 9)
		r += r * 10 + (num[i++] - '0');
	r %= max;
	return (r < 0 ? -r : r);
}
