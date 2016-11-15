/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:20:33 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/02 18:51:29 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		str_cmp_error(t_env *env)
{
	if (env->k != 1)
		error(env);
}

static void		str_compare(char *file, char *test, t_env *env)
{
	if (ft_strcmp(file, test) == 0)
		env->k++;
}

void			compare(t_env *env)
{
	t_fillit	*file;
	t_fillit	*test;

	env->i = 1;
	file = env->file;
	if (ft_strlen(file->patern) != 20)
		exit(0);
	while (env->i <= env->count_file)
	{
		env->j = 1;
		env->k = 0;
		test = env->test;
		while (env->j <= env->count_test)
		{
			str_compare(file->patern, test->patern, env);
			env->j++;
			if (test->next != NULL)
				test = test->next;
		}
		env->i++;
		str_cmp_error(env);
		if (file->next != NULL)
			file = file->next;
	}
}
