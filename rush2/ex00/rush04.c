/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:18:24 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/01 19:22:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char lettre);

void	ligne1(int longueur)
{
	int sx;

	sx = 0;
	if (longueur == 1)
		sx = 1;
	ft_putchar('A');
	while (longueur > 2)
	{
		longueur--;
		ft_putchar('B');
	}
	if (sx == 0)
		ft_putchar('C');
}

void	ligne2(int longueur)
{
	int sx;

	sx = 0;
	if (longueur == 1)
		sx = 1;
	ft_putchar('B');
	while (longueur > 2)
	{
		ft_putchar(' ');
		longueur--;
	}
	if (sx == 0)
		ft_putchar('B');
}

void	ligne3(int longueur)
{
	int sx;

	sx = 0;
	if (longueur == 1)
		sx = 1;
	ft_putchar('C');
	while (longueur > 2)
	{
		longueur--;
		ft_putchar('B');
	}
	if (sx == 0)
		ft_putchar('A');
}

void	ligne(int longueur, int position)
{
	if (position == 0)
		ligne1(longueur);
	else if (position == 1)
		ligne2(longueur);
	else if (position == 2)
		ligne3(longueur);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int sy;

	sy = 0;
	if (y == 1)
		sy = 1;
	if (x > 0 && y > 0)
	{
		ligne(x, 0);
		y--;
		while (y > 1)
		{
			ligne(x, 1);
			y--;
		}
		if (sy == 0)
			ligne(x, 2);
	}
}
