/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:20:13 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/12 15:53:33 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	int		i;
	char	*byte;

	i = 0;
	byte = (char*)s;
	while (byte[i] && n > 0)
	{
		byte[i] = 0;
		i++;
		n--;
	}
}
