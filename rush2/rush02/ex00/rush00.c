/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:17:49 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/15 20:37:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char lettre)
{
	write(1, &lettre, 1);
}

void	ligne(int column, char tab[3])
{
	int sx;

	sx = 0;
	if (column == 1)
		sx = 1;
	column--;
	ft_putchar(tab[0]);
	while (column > 1)
	{
		ft_putchar(tab[1]);
		column--;
	}
	if (sx == 0)
		ft_putchar(tab[2]);

	ft_putchar('\n');
}

void	rush00(char tab[3][3], int y, int x)
{
	int sy;

	sy = 0;
	if (y == 1)
		sy = 1;
	if (x > 0 && y > 0)
	{
		ligne(x, tab[0]);
		y--;
		while (y > 1)
		{
			ligne( x, tab[1]);
			y--;
		}
		if (sy == 0)
			ligne(x, tab[2]);
	}
}

int		main(int argc, char** argv)
{
	char tab[3][3];
	int		i;
	int		j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	if (argc == 4)
	{
		while (j <= 2)
		{
			i = 0;
			while ( i <= 2)
			{
				tab[j][i++] = argv[1][x++];
			}
			j++;
		}
		rush00(tab, atoi(argv[2]), atoi(argv[3]));
	}
	return (0);
}
