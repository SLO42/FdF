/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:58:53 by saolivei          #+#    #+#             */
/*   Updated: 2019/03/20 15:03:39 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	will create an array from a list of strings
*/

static char	**ft_varray(int argc, va_list args)
{
	int		i;
	char	**ret;
	char	*tmp;

	i = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * argc + 1)))
		return (NULL);
	while (i < argc)
	{
		tmp = va_arg(args, char *);
		if (!(ret[i] = ft_strdup(tmp)))
		{
			free(ret);
			ret = NULL;
			return (ret);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char		**ft_array(int num, ...)
{
	va_list	args;

	if (num < 1)
		return (NULL);
	va_start(args, num);
	return (ft_varray(num, args));
}
