/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:06:28 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/18 16:10:21 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		i;
	int		cp;
	char	*strdp;

	i = 0;
	cp = ft_strlen(str) + 1;
	strdp = malloc(sizeof(char) * cp);
	if (strdp == NULL)
		return (NULL);
	else
	{
		while (str[i] != '\0')
		{
			strdp[i] = str[i];
			i++;
		}
		strdp[i] = '\0';
		return (strdp);
	}
}
