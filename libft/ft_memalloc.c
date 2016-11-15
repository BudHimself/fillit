/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:17:17 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/14 19:11:10 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*memory;
	char	*tmp;

	if (!(memory = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	tmp = (char *)memory;
	while (size--)
		*tmp++ = 0;
	return (memory);
}
