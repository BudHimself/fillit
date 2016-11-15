/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:13:54 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/21 21:12:42 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int		len;

	if (ft_str_printable(base) == 0)
		return (ft_putstr("base non valide\n"));
	len = ft_strlen(base);
	if (nbr >= len)
	{
		ft_putnbr_base((nbr / len), base);
		ft_putnbr_base((nbr % len), base);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}
