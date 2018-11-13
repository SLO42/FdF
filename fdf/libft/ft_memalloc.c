/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:09:36 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/21 18:23:02 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*any;

	if (!(any = (void *)malloc(sizeof(void*) * size)))
		return (NULL);
	ft_bzero(any, size);
	return (any);
}
