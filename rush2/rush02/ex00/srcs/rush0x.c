/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:48:39 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/16 21:53:26 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

int		ft_check_line(char big, char tab)
{
	if (big == tab)
		return (1);
	else
		return (0);
}

int		line(char *big, int column, char tab[3])
{
	int sx;
	int check;
	int save;

	save = column;
	check = 0;
	sx = 0;
	if (column == 1)
		sx = 1;
	if (!ft_check_line(big[save - column--], tab[0]))
		return (0);
	while (column > 1)
		if (!(ft_check_line(big[save - column--], tab[1])))
			return (0);
	if (sx == 0)
		if (!(ft_check_line(big[save - column--], tab[2])))
			return (0);
	return (1);
}

int		rush0x(char **big, char tab[3][3], int y, int x)
{
	int sy;
	int check;
	int save;

	save = y;
	check = 0;
	sy = 0;
	if (y == 1)
		sy = 1;
	if (x > 0 && y > 0)
	{
		if (!(line(big[save - y--], x, tab[0])))
			return (0);
		while (y > 1)
			if (!(line(big[save - y--], x, tab[1])))
				return (0);
		if (sy == 0)
			if (!(line(big[save - y--], x, tab[2])))
				return (0);
	}
	return (1);
}
