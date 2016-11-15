/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:16:16 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/14 19:02:12 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strstrcut(const char *s1, const char *s2, int i, int i2)
{
	char		*dst;
	char		*src;
	int			save;

	dst = (char *)s1;
	src = (char *)s2;
	save = 0;
	while (dst[i] && src[i2])
	{
		save = i;
		while (dst[i] && src[i2] && dst[i] == src[i2])
		{
			i++;
			i2++;
		}
		if (!src[i2] && dst[save])
		{
			i2 = 0;
			return (&dst[save]);
		}
		i = save;
		i2 = 0;
		i++;
	}
	return (NULL);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	char		*dst;
	int			i;
	int			i2;

	dst = (char *)s1;
	i = 0;
	i2 = 0;
	if (!*s2)
		return (dst);
	else
		return (ft_strstrcut(s1, s2, i, i2));
}
