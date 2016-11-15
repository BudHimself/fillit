/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:20:15 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/14 17:07:36 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			init_env(t_env *env)
{
	env->file = NULL;
	env->test = NULL;
	env->count_file = 0;
	env->count_test = 0;
	env->first_pos = NULL;
	env->error = 0;
	env->i = 0;
	env->j = 0;
	env->k = 0;
	env->l = 0;
	env->control = 0;
}
