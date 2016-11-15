/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:16:25 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/08 18:22:46 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		load_test(char *buf, t_env *env)
{
	t_fillit	*maillon;
	t_fillit	*tmp;

	tmp = env->test;
	env->count_test++;
	if (!(maillon = (t_fillit *)malloc(sizeof(t_fillit))))
		exit(0);
	maillon->patern = ft_strdup(buf);
	maillon->next = NULL;
	if (env->test == NULL)
		env->test = maillon;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = maillon;
	}
}

static void		load_file(char *buf, t_env *env)
{
	t_fillit	*maillon;
	t_fillit	*tmp;

	tmp = env->file;
	env->count_file++;
	if (!(maillon = (t_fillit *)malloc(sizeof(t_fillit))))
		exit(0);
	maillon->patern = ft_strdup(buf);
	maillon->next = NULL;
	if (env->file == NULL)
		env->file = maillon;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = maillon;
	}
}

void			load_struct(char *buf, t_env *env)
{
	if (env->direction == 1)
		load_file(buf, env);
	else if (env->direction == 2)
		load_test(buf, env);
}
