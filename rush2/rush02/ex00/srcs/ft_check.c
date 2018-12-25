/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 21:03:05 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/16 21:56:25 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

void	ft_check_04(char **big, int y, int x, int o)
{
	char tab[3][3];

	tab[0][0] = 'A';
	tab[0][1] = 'B';
	tab[0][2] = 'C';
	tab[1][0] = 'B';
	tab[1][1] = ' ';
	tab[1][2] = 'B';
	tab[2][0] = 'C';
	tab[2][1] = 'B';
	tab[2][2] = 'A';
	if (rush0x(big, tab, y, x))
		ft_print(o * 11, y, x);
	else
		ft_print(o, y, x);
}

void	ft_check_03(char **big, int y, int x, int o)
{
	char tab[3][3];

	tab[0][0] = 'A';
	tab[0][1] = 'B';
	tab[0][2] = 'C';
	tab[1][0] = 'B';
	tab[1][1] = ' ';
	tab[1][2] = 'B';
	tab[2][0] = 'A';
	tab[2][1] = 'B';
	tab[2][2] = 'C';
	if (rush0x(big, tab, y, x))
		ft_check_04(big, y, x, o * 7);
	else
		ft_check_04(big, y, x, o);
}

void	ft_check_02(char **big, int y, int x, int o)
{
	char tab[3][3];

	tab[0][0] = 'A';
	tab[0][1] = 'B';
	tab[0][2] = 'A';
	tab[1][0] = 'B';
	tab[1][1] = ' ';
	tab[1][2] = 'B';
	tab[2][0] = 'C';
	tab[2][1] = 'B';
	tab[2][2] = 'C';
	if (rush0x(big, tab, y, x))
		ft_check_03(big, y, x, o * 5);
	else
		ft_check_03(big, y, x, o);
}

void	ft_check_01(char **big, int y, int x, int o)
{
	char tab[3][3];

	tab[0][0] = '/';
	tab[0][1] = '*';
	tab[0][2] = '\\';
	tab[1][0] = '*';
	tab[1][1] = ' ';
	tab[1][2] = '*';
	tab[2][0] = '\\';
	tab[2][1] = '*';
	tab[2][2] = '/';
	if (rush0x(big, tab, y, x))
		ft_check_02(big, y, x, o * 3);
	else
		ft_check_02(big, y, x, o);
}

void	ft_check_00(char **big, int y, int x, int o)
{
	char tab[3][3];

	tab[0][0] = 'o';
	tab[0][1] = '-';
	tab[0][2] = 'o';
	tab[1][0] = '|';
	tab[1][1] = ' ';
	tab[1][2] = '|';
	tab[2][0] = 'o';
	tab[2][1] = '-';
	tab[2][2] = 'o';
	if (rush0x(big, tab, y, x))
		ft_check_01(big, y, x, o * 2);
	else
		ft_check_01(big, y, x, o);
}
