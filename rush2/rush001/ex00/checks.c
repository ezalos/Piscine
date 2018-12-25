/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:47:42 by jbarment          #+#    #+#             */
/*   Updated: 2018/09/11 12:39:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_ok(char **tab, char value, int pos);

void	ft_print_grid(char **solution)
{
	int i;
	int j;

	i = 0;
	if (solution[0][9] != 1)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
	}
	else
	{
		while (i < 9)
		{
			j = 0;
			while (j < 9)
			{
				write(1, &solution[i][j], 1);
				if (j != 8)
					write(1, " ", 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}

int		is_ok_block(char **tab, char value, int pos)
{
	int	line;
	int column;
	int	i;
	int	j;
	int block_column;

	line = pos / 9;
	column = pos % 9;
	block_column = (column / 3) * 3;
	i = (line / 3) * 3;
	while (i < (line / 3) * 3 + 3)
	{
		j = block_column;
		while (j < block_column + 3)
		{
			if (tab[i][j] == value && (i != line || j != column))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		input_check_2(char **tab)
{
	int	i;
	int	j;
	int	numbers;

	numbers = 0;
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (tab[i][j] != '0')
			{
				if (is_ok(tab, tab[i][j], 9 * i + j) == 0)
					return (0);
				numbers = numbers + 1;
			}
			j++;
		}
		i++;
	}
	if (numbers < 17)
		return (0);
	return (1);
}

int		is_ok(char **tab, char value, int pos)
{
	int	line;
	int column;
	int	i;

	line = pos / 9;
	column = pos % 9;
	i = 0;
	while (i < 9)
	{
		if (tab[line][i] == value && i != column)
			return (0);
		if (i != line && tab[i][column] == value)
			return (0);
		i++;
	}
	return (is_ok_block(tab, value, pos));
}

int		input_check(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	if (argc != 10)
		return (0);
	while (i < 10)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '.' && (argv[i][j] < '1' || argv[i][j] > '9'))
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}
