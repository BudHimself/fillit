/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:54:11 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/14 16:35:10 by fhenry           ###   ########.fr       */
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

static void		save_data(t_env *env, t_pos *pos)
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

static t_pos	*creat_struct(t_env *env)
{
	t_pos		*pos;
	t_pos		*tmp;

	tmp = env->first_pos;
	pos = env->first_pos;
	if (!(pos = (t_pos *)malloc(sizeof(t_pos))))
		exit(0);
	pos->next = NULL;
	pos->c = 66;
	if (env->first_pos == NULL)
	{
		pos->c = 65;
		env->first_pos = pos;
	}
	else
	{
		while (tmp->next != NULL)
		{
			pos->c += 1;
			tmp = tmp->next;
		}
		tmp->next = pos;
	}
	return (pos);
}

static void		convert2table(char *patern, t_env *env)
{
	int			l;
	int			c;

	env->j = 0;
	l = 0;
	c = 0;
	while (patern[env->j] != '\0')
	{
		env->table[l][c] = patern[env->j];
		c++;
		env->j++;
		if (patern[env->j] == '\n')
		{
			env->table[l][c] = '\0';
			l++;
			c = 0;
			env->j++;
		}
	}
}

void			find_data(t_env *env)
{
	t_fillit	*file;
	t_pos		*pos;
	int			l;

	file = env->file;
	l = 0;
	if (!(env->table = (char **)malloc(sizeof(char *) * (env->size + 1))))
		exit(0);
	while (l < (env->size + 1))
	{
		if (!(env->table[l] = (char *)malloc(sizeof(char) * (env->size + 1))))
		{
			env->table[l][env->size + 1] = '\0';
			exit(0);
		}
		l++;
	}
	while (file)
	{
		convert2table(file->patern, env);
		pos = creat_struct(env);
		save_data(env, pos);
		file = file->next;
	}
}
