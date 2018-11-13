/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:02:15 by saolivei          #+#    #+#             */
/*   Updated: 2018/07/26 14:06:17 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *new;

	new = *alst;
	while (new)
	{
		temp = new;
		del(new->content, new->content_size);
		free(new);
		new = temp->next;
	}
	*alst = NULL;
}
