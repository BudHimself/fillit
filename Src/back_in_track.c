/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_in_track.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:34:16 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/15 12:37:42 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		raz_track(t_pos *tmp)
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
}

t_pos			*back_in_track(t_env *env, t_pos *track)
{
	t_pos		*tmp;
	int			l;
	int			c;

	tmp = env->first_pos;
	raz_track(track);
	if (track->c > 'A')
	{
		while (tmp->c < (track->c - 1))
			tmp = tmp->next;
	}
	track = tmp;
	l = 0;
	while (l < env->size)
	{
		c = 0;
		while (env->table[l][c])
		{
			if (env->table[l][c] == track->c)
				env->table[l][c] = '.';
			c++;
		}
		l++;
	}
	return (track);
}
