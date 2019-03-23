/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:29:46 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/29 19:04:12 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long n)
{
	int		len;
	char	*nums;
	int		flag;

	flag = 0;
	len = ft_numlen(n);
	if (n < 0)
		flag = 1;
	if (!(nums = (char*)malloc(sizeof(char) * (len + 1 + flag))))
		return (NULL);
	nums[len + flag] = '\0';
	while (--len + flag >= flag)
	{
		if (n < 0)
			nums[len + flag] = ((n % 10) * -1) + 48;
		else
			nums[len + flag] = (n % 10) + 48;
		n /= 10;
	}
	if (flag == 1)
		nums[0] = '-';
	return (nums);
}
