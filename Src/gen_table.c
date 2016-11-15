/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:01:33 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/14 16:33:45 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		load(t_env *env)
{
	int			l;
	int			c;

	l = 0;
	c = 0;
	while (l < env->size)
	{
		while (c < env->size)
		{
			env->table[l][c] = '.';
			c++;
		}
		c = 0;
		l++;
	}
}

void			gen_table(t_env *env)
{
	int			l;

	l = 0;
	if (!(env->table = (char **)malloc(sizeof(char *) * (env->size + 1))))
		exit(0);
	env->table[env->size + 1] = NULL;
	while (l < (env->size + 1))
	{
		if (!(env->table[l] = (char *)malloc(sizeof(char) * (env->size + 1))))
			exit(0);
		env->table[l][env->size + 1] = '\0';
		l++;
	}
	load(env);
}
