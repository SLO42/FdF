/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:10:38 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 18:41:09 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*nums;
	int		flag;

	flag = 0;
	len = ft_numlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		flag = 1;
	if (!(nums = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nums[len] = '\0';
	while (--len + flag >= flag)
	{
		if (n < 0)
			nums[len] = ((n % 10) * -1) + 48;
		else
			nums[len] = (n % 10) + 48;
		n /= 10;
	}
	if (flag == 1)
		nums[0] = '-';
	return (nums);
}
