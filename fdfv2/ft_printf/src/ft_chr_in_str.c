/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:17:02 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 15:50:19 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chr_in_str(const char *t, int s, char c, t_printf *p)
{
	if (c == 0)
		ft_exit(-4, p);
	while (--s >= 0)
	{
		if (t[s] == c)
			return (1);
	}
	return (0);
}
