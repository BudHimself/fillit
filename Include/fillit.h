/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:54:00 by fhenry            #+#    #+#             */
/*   Updated: 2016/03/15 12:41:16 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_pos
{
	int				x1;
	int				x2;
	int				x3;
	int				x4;
	int				y1;
	int				y2;
	int				y3;
	int				y4;
	char			c;
	struct s_pos	*next;
}					t_pos;

typedef struct		s_fillit
{
	char			*patern;
	struct s_fillit	*next;
}					t_fillit;

typedef struct		s_env
{
	t_fillit		*file;
	t_fillit		*test;
	t_fillit		*third;
	int				count_file;
	int				count_test;
	int				i;
	int				j;
	int				k;
	int				l;
	int				error;
	int				size;
	int				fd_file;
	int				fd_test;
	int				direction;
	t_pos			*first_pos;
	t_pos			*second_pos;
	char			**table;
	int				current_piece;
	int				control;
}					t_env;

void				read_buf(t_env *env);
void				load_struct(char *buf, t_env *env);
void				smaller_size(t_env *env);
void				compare(t_env *env);
void				init_ref(t_env *env);
void				save_position(t_env *env);
void				find_data(t_env *env);
void				ref_abs(t_env *env);
void				error(t_env *env);
void				init_env(t_env *env);
void				gen_table(t_env *env);
void				backtracking(t_env *env);
t_pos				*back_in_track(t_env *env, t_pos *track);
int					check_position(t_env *env, t_pos *track);
void				resize(t_env *env);

#endif
