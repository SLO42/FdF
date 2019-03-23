/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:57:08 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/20 16:25:37 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a string from a list of arguments. seperated by del.
*/

static char	*ft_vstringd(int argc, int sep, va_list args)
{
	t_vector	*output;
	char		*tmp;
	char		*septmp;
	int			i;

	if (!(output = ft_memalloc(sizeof(t_vector)))
		|| (ft_vector_init(output, 4) == -1)
		|| !(septmp = (char *)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	i = 0;
	septmp[0] = sep;
	while (i < argc)
	{
		tmp = va_arg(args, char*);
		ft_vector_appened(output, tmp);
		if (argc - i != 1)
			ft_vector_nappend(output, septmp, 1);
		i++;
	}
	tmp = ft_strdup(output->data);
	ft_vector_free(output);
	free(septmp);
	return (tmp);
}

char		*ft_stringd(int num, int del, ...)
{
	va_list args;

	if (num < 1)
		return (NULL);
	va_start(args, del);
	return (ft_vstringd(num, del, args));
}
