/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:45:12 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/07 16:26:12 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		how_much_elem(t_env *env)
{
	int			count;
	t_fillit	*tmp;

	tmp = env->file;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void			smaller_size(t_env *env)
{
	int			smaller;
	int			cube;

	smaller = 4 * how_much_elem(env);
	cube = 2;
	env->size = 2;
	while (smaller > (cube * cube))
	{
		cube++;
		env->size++;
	}
}
