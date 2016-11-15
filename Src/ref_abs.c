/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:26:52 by fhenry            #+#    #+#             */
/*   Updated: 2016/02/23 15:25:23 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ref_abs(t_env *env)
{
	t_pos		*tmp;

	tmp = env->first_pos;
	while (tmp)
	{
		while (tmp->x1 > 0 && tmp->x2 > 0 && tmp->x3 > 0 && tmp->x4 > 0)
		{
			tmp->x1 -= 1;
			tmp->x2 -= 1;
			tmp->x3 -= 1;
			tmp->x4 -= 1;
		}
		while (tmp->y1 > 0 && tmp->y2 > 0 && tmp->y3 > 0 && tmp->y4 > 0)
		{
			tmp->y1 -= 1;
			tmp->y2 -= 1;
			tmp->y3 -= 1;
			tmp->y4 -= 1;
		}
		tmp = tmp->next;
	}
}
