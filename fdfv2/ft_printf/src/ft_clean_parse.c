/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:10:06 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 15:50:23 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_parse(t_printf *prtf)
{
	prtf->args->width = 0;
	prtf->args->pre = -1;
	prtf->args->spec = 0;
	prtf->args->flags->f = 1;
	prtf->args->flags->left_just = 1;
	prtf->args->flags->prepend_sign = 1;
	prtf->args->flags->prepend_space = 1;
	prtf->args->flags->alt_form = 1;
	prtf->args->flags->pad_zeros = 1;
	prtf->args->stats->l = 1;
	prtf->args->stats->pf_hh = 1;
	prtf->args->stats->pf_h = 1;
	prtf->args->stats->pf_l = 1;
	prtf->args->stats->pf_ll = 1;
	prtf->args->stats->pf__l = 1;
	prtf->args->stats->sign = 0;
	DIFW = 0;
	DIFP = 0;
}
