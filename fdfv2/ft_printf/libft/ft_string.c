/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:01:45 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/20 15:00:07 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a string from a list of arguments. NOT SEPERATED BY ANY VALUE
*/

static char	*ft_vstring(int argc, va_list args)
{
	t_vector	*output;
	char		*tmp;
	int			i;

	if (!(output = ft_memalloc(sizeof(t_vector)))
		|| (ft_vector_init(output, 4)) == -1)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		tmp = va_arg(args, char *);
		ft_vector_appened(output, tmp);
	}
	tmp = ft_strdup(output->data);
	ft_vector_free(output);
	return (tmp);
}

char		*ft_string(int num, ...)
{
	va_list args;

	if (num < 1)
		return (NULL);
	va_start(args, num);
	return (ft_vstring(num, args));
}
