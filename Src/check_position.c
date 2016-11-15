/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:36:38 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/14 16:33:23 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_position(t_env *env, t_pos *track)
{
	if (env->table[track->y1][track->x1] == '.' &&
			env->table[track->y2][track->x2] == '.' &&
			env->table[track->y3][track->x3] == '.' &&
			env->table[track->y4][track->x4] == '.' &&
			track->x1 <= env->size && track->x2 <= env->size &&
			track->x3 <= env->size && track->x4 <= env->size &&
			track->y1 <= env->size && track->y2 <= env->size &&
			track->y3 <= env->size && track->y4 <= env->size)
	{
		env->table[track->y1][track->x1] = track->c;
		env->table[track->y2][track->x2] = track->c;
		env->table[track->y3][track->x3] = track->c;
		env->table[track->y4][track->x4] = track->c;
		return (1);
	}
	else
		return (0);
}
