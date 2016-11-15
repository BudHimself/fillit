/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:16:16 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/21 16:23:53 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strnstrcut(const char *s1, const char *s2, size_t n,
		size_t i)
{
	char		*dst;
	char		*src;
	int			i2;
	int			save;

	dst = (char*)s1;
	src = (char*)s2;
	i2 = 0;
	save = 0;
	while (dst[i] && src[i2] && i <= n)
	{
		save = i;
		while (dst[i] && src[i2] && dst[i] == src[i2] && i <= n)
		{
			i++;
			i2++;
		}
		if (!src[i2] && dst[save] && i <= n)
			return (&dst[save]);
		i = save;
		i2 = 0;
		i++;
	}
	return (NULL);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char		*dst;
	size_t		i;

	i = 0;
	dst = (char*)s1;
	if (!*s2)
		return (dst);
	else
		return (ft_strnstrcut(s1, s2, n, i));
}
