/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:53:11 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/26 15:55:43 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *start_lst)
{
	size_t i;

	i = 0;
	while (start_lst)
	{
		start_lst = start_lst->next;
		i++;
	}
	return (i);
}
