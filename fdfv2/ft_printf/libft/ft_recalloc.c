/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:48:52 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 16:13:56 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_recalloc(char *ptr, size_t src_size, size_t new_size)
{
	char	*new_ptr;

	if (!new_size)
	{
		if (ptr)
			free(ptr);
		return (ptr);
	}
	if (!ptr)
		return (ft_memalloc(new_size));
	if (new_size <= src_size)
		return (ptr);
	new_ptr = ft_strnew(new_size);
	if (new_ptr)
	{
		ft_memcpy(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}
