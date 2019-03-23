/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:09:09 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 16:17:34 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlower(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strupper(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 95 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	return (str);
}
