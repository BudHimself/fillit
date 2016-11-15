/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:34:41 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/15 13:55:59 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			unload_file(t_env *env)
{
	t_fillit		*tmp;
	t_fillit		*del;

	tmp = env->file;
	del = tmp;
	while (tmp)
	{
		tmp = tmp->next;
		free(del->patern);
		free(del);
		del = tmp;
	}
	close(env->fd_file);
}

static void			unload_test(t_env *env)
{
	t_fillit		*tmp;
	t_fillit		*del;

	tmp = env->test;
	del = tmp;
	while (tmp)
	{
		tmp = tmp->next;
		free(del->patern);
		free(del);
		del = tmp;
	}
	close(env->fd_test);
	unload_file(env);
}

void				error(t_env *env)
{
	if (env->error == 1)
		unload_file(env);
	if (env->error == 2)
		unload_test(env);
	ft_putstr("error\n");
	exit(0);
}
