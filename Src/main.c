/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:45:18 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/02 03:56:35 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print(t_env *env)
{
	int			l;
	t_pos		*tmp;
	t_pos		*del;

	l = 0;
	while (l < env->size)
	{
		ft_putstr(env->table[l]);
		ft_putchar('\n');
		l++;
	}
	tmp = env->first_pos;
	del = tmp;
	while (tmp)
	{
		tmp = tmp->next;
		free(del);
		del = tmp;
	}
	free(env->table);
}

static int		usage(void)
{
	ft_putstr("usage: ./fillit [target_file]\n");
	exit(0);
}

static void		read_extern(t_env *env)
{
	env->direction = 2;
	if ((env->fd_test = open("extern_file.txt", O_RDONLY)) == -1)
		exit(0);
	read_buf(env);
}

static void		read_file(char *buf, t_env *env)
{
	env->direction = 1;
	if ((env->fd_file = open(buf, O_RDONLY)) == -1)
	{
		env->error = 1;
		error(env);
	}
	read_buf(env);
}

int				main(int ac, char **av)
{
	t_env		env;

	init_env(&env);
	if (ac != 2)
		usage();
	read_file(av[1], &env);
	read_extern(&env);
	compare(&env);
	find_data(&env);
	ref_abs(&env);
	smaller_size(&env);
	gen_table(&env);
	backtracking(&env);
	print(&env);
	return (0);
}
