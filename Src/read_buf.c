/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:31:12 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/14 16:30:23 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		check_buff(int red, int i, int j, t_env *env)
{
	if (red < BUFF_SIZE)
	{
		env->error++;
		error(env);
	}
	if (i == j)
	{
		env->error++;
		error(env);
	}
}

void			read_buf(t_env *env)
{
	int			fd;
	int			red;
	char		buf[BUFF_SIZE + 1];

	if (env->direction == 1)
		fd = env->fd_file;
	else
		fd = env->fd_test;
	while ((red = read(fd, buf, BUFF_SIZE)))
	{
		check_buff(red, 1, 0, env);
		if (env->k++ == 0)
		{
			buf[BUFF_SIZE] = '\0';
			env->i++;
			load_struct(buf, env);
		}
		if (env->k-- == 1)
		{
			if (read(fd, buf, 1) > 0)
				env->j++;
		}
	}
	check_buff(BUFF_SIZE, env->i, env->j, env);
	close(fd);
}
