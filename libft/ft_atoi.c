/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:47:58 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/18 14:11:01 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_work(const char *str, int i, int multi, int nbr)
{
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (i >= 20)
		return (-1);
	while (--i > -1)
	{
		nbr += (str[i] - '0') * multi;
		multi *= 10;
	}
	return (nbr);
}

static int	ft_negative(const char *str, int i, int multi, int nbr)
{
	i++;
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (i >= 21)
		return (0);
	while (--i)
	{
		nbr += (str[i] - '0') * multi;
		multi *= 10;
	}
	return (-nbr);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		multi;

	i = 0;
	nbr = 0;
	multi = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\r' || *str == '\f')
		str++;
	if (*str == '+' && ft_isdigit(str[i + 1]))
		str++;
	if (*str == '-' && ft_isdigit(str[i + 1]))
		return (ft_negative(str, i, multi, nbr));
	else if (ft_isdigit(str[i]))
		return (ft_work(str, i, multi, nbr));
	return (0);
}
