/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:18:58 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/16 21:31:22 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

int		ft_lines_tab(char **big)
{
	int y;

	y = 0;
	while (big[y])
		y++;
	return (y);
}

int		ft_columns_tab(char **big)
{
	int x;

	x = 0;
	while (big[0][x])
		x++;
	return (x);
}

void	ft_brain(char **big)
{
	int y;
	int x;

	y = ft_lines_tab(big);
	x = ft_columns_tab(big);
	if (x == 0 || y == 0)
		error();
	else if (x == 1 && y == 1 && big[0][0] == 'A')
	{
		ft_print(5 * 7 * 11, y, x);
	}
	else
		ft_check_00(big, y, x, 1);
	ft_putchar('\n');
}
