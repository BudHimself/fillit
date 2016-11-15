/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:00:57 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/03 16:05:47 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		save_ref(int line, int col, int nbr, t_pos *pos)
{
	if (nbr == 1)
	{
		pos->x1 = col;
		pos->y1 = line;
	}
	else if (nbr == 2)
	{
		pos->x2 = col;
		pos->y2 = line;
	}
	else if (nbr == 3)
	{
		pos->x3 = col;
		pos->y3 = line;
	}
	else if (nbr == 4)
	{
		pos->x4 = col;
		pos->y4 = line;
	}
}

void			save_data(t_env *env, t_pos *pos)
{
	int			l;
	int			c;
	int			nbr;
	t_env		*a;

	a = env;
	l = 0;
	nbr = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (env->table[l][c] == '#')
			{
				nbr++;
				save_ref(l, c, nbr, pos);
			}
			c++;
		}
		l++;
	}
}
