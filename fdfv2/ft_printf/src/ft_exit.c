/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:30:06 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 15:50:25 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_it_all(t_printf *prtf)
{
	if (prtf->output != NULL)
	{
		ft_vector_free(prtf->output);
		free(prtf->output);
	}
	if (prtf->fmt && prtf->len)
	{
		free(prtf->fmt);
		prtf->fmt = NULL;
	}
	if (prtf->args != NULL)
	{
		if (prtf->args->flags != NULL)
			free(prtf->args->flags);
		if (prtf->args->stats != NULL)
			free(prtf->args->stats);
		free(prtf->args);
	}
}

void	ft_del_prtf(t_printf *prtf)
{
	if (prtf->args != NULL)
	{
		free_it_all(prtf);
		free(prtf);
	}
}

void	ft_exit(short num, t_printf *prtf)
{
	if (num == 1)
		return (ft_del_prtf(prtf));
	if (num == -1)
	{
		ft_putstr("Error Allocatng Memory");
		ft_del_prtf(prtf);
		exit(-1);
	}
	else if (num == -2)
	{
		ft_putstr("ERROR impropper conversion");
		ft_del_prtf(prtf);
		exit(-2);
	}
	else if (num == '%')
	{
		ft_putstr("big dingo dango %!!! dingo");
		ft_del_prtf((prtf));
		exit(-3);
	}
	if (num == -4)
		ft_putstr("Undefined Behavior. BAD!");
	ft_del_prtf(prtf);
	exit(-4);
}
