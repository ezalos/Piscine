/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:24:13 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/16 21:58:46 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

void	ft_print2(int o, int y, int x)
{
	if (o % 11 == 0)
	{
		ft_putstr("[colle-04] [");
		ft_putnbr(y);
		ft_putstr("] [");
		ft_putnbr(x);
		ft_putstr("]");
	}
}

void	ft_print1(int o, int y, int x)
{
	if (o % 5 == 0)
	{
		ft_putstr("[colle-02] [");
		ft_putnbr(y);
		ft_putstr("] [");
		ft_putnbr(x);
		ft_putstr("]");
		if (1 < (o /= 5))
			ft_putstr(" || ");
	}
	if (o % 7 == 0)
	{
		ft_putstr("[colle-03] [");
		ft_putnbr(y);
		ft_putstr("] [");
		ft_putnbr(x);
		ft_putstr("]");
		if (1 < (o /= 7))
			ft_putstr(" || ");
	}
	ft_print2(o, y, x);
}

void	ft_print(int o, int y, int x)
{
	if (o == 1)
		error();
	if (o % 2 == 0)
	{
		ft_putstr("[colle-00] [");
		ft_putnbr(y);
		ft_putstr("] [");
		ft_putnbr(x);
		ft_putstr("]");
		if (1 < (o /= 2))
			ft_putstr(" || ");
	}
	if (o % 3 == 0)
	{
		ft_putstr("[colle-01] [");
		ft_putnbr(y);
		ft_putstr("] [");
		ft_putnbr(x);
		ft_putstr("]");
		if (1 < (o /= 3))
			ft_putstr(" || ");
	}
	ft_print1(o, y, x);
}
