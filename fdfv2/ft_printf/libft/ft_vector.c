/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:00:16 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/24 13:28:56 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vector_init(t_vector *vector, size_t init_cap)
{
	if (!vector || !init_cap)
		return (-1);
	vector->len = 0;
	vector->cap = init_cap;
	if ((vector->data = ft_memalloc(sizeof(char) * vector->cap)) == NULL)
		return (-1);
	return (0);
}

void	ft_vector_appened(t_vector *vector, char *n_d)
{
	size_t nd_len;

	nd_len = ft_strlen(n_d);
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, n_d, nd_len);
	vector->len += nd_len;
}

void	ft_vector_resize(t_vector *vector, size_t min)
{
	size_t	mllc_size;

	if (!(vector->data))
		ft_vector_init(vector, min);
	mllc_size = vector->cap;
	while (mllc_size < min)
		mllc_size *= 2;
	vector->data = ft_recalloc(vector->data, vector->len, mllc_size);
	vector->cap = mllc_size;
}

void	ft_vector_nappend(t_vector *vector, char *newdata, size_t n)
{
	size_t	nd_len;

	nd_len = n;
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void	ft_vector_free(t_vector *vector)
{
	if (vector->data && vector->cap > 0)
	{
		free(vector->data);
		vector->data = NULL;
	}
}
