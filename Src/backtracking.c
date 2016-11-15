/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:15:40 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/15 12:38:40 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		work_y(t_pos *track)
{
	while (track->x1 > 0 && track->x2 > 0 && track->x3 > 0 && track->x4 > 0)
	{
		track->x1 -= 1;
		track->x2 -= 1;
		track->x3 -= 1;
		track->x4 -= 1;
	}
	track->y1 += 1;
	track->y2 += 1;
	track->y3 += 1;
	track->y4 += 1;
}

static void		work(t_env *env, t_pos *track)
{
	if (track->x1 <= env->size ||
			track->x2 <= env->size ||
			track->x3 <= env->size ||
			track->x4 <= env->size)
	{
		track->x1 += 1;
		track->x2 += 1;
		track->x3 += 1;
		track->x4 += 1;
	}
	else
		work_y(track);
}

static int		check_moove_a(t_env *env, t_pos *track)
{
	if ((track->x1 == env->size || track->x2 == env->size ||
			track->x3 == env->size || track->x4 == env->size) &&
			(track->y1 == env->size || track->y2 == env->size ||
			track->y3 == env->size || track->y4 == env->size) &&
			track->c > 'A')
		return (1);
	else
		return (0);
}

static int		check_resize(t_env *env, t_pos *track)
{
	if ((track->x1 == env->size || track->x2 == env->size ||
			track->x3 == env->size || track->x4 == env->size) &&
			(track->y1 == env->size || track->y2 == env->size ||
			track->y3 == env->size || track->y4 == env->size) &&
			track->c == 'A')
		return (1);
	else
		return (0);
}

void			backtracking(t_env *env)
{
	t_pos		*track;

	track = env->first_pos;
	while (env->control < env->count_file)
	{
		if (check_position(env, track))
		{
			track = track->next;
			env->control++;
		}
		else if (check_resize(env, track))
		{
			ref_abs(env);
			resize(env);
		}
		else if (check_moove_a(env, track))
		{
			track = back_in_track(env, track);
			work(env, track);
			env->control--;
		}
		else
			work(env, track);
	}
}
