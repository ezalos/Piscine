/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 20:44:26 by jbarment          #+#    #+#             */
/*   Updated: 2018/09/09 20:44:32 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_ok(char **tab, char value, int pos);

void	fill_sudoku(char **argv, char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
				tab[i - 1][j] = '0';
			else
				tab[i - 1][j] = argv[i][j];
			j++;
		}
		i++;
	}
}

void	copy_solution(char **tab, char **solution)
{
	int	i;
	int	j;

	if (solution[0][9] == 0)
	{
		i = 0;
		while (i < 9)
		{
			j = 0;
			while (j < 9)
			{
				solution[i][j] = tab[i][j];
				j++;
			}
			i++;
		}
	}
	solution[0][9] = solution[0][9] + 1;
}

void	ft_fill_tab(char **tab, int *pos_tab, int *possib_tab)
{
	int		pos;
	char	value;
	int		i;

	pos = 0;
	i = 0;
	while (i < 81)
	{
		possib_tab[i] = 0;
		pos_tab[i] = i;
		i++;
	}
	pos_tab[81] = 81;
	while (pos < 81)
	{
		value = '1';
		while (value <= '9')
		{
			if (is_ok(tab, value, pos))
				possib_tab[pos]++;
			value++;
		}
		pos++;
	}
}

void	ft_order_tab(int *pos_tab, int *possib_tab)
{
	int	i;
	int	j;
	int tmp;

	i = 0;
	j = 0;
	while (i < 81)
	{
		j = 0;
		while (j < 80)
		{
			if (possib_tab[j] > possib_tab[j + 1])
			{
				tmp = possib_tab[j];
				possib_tab[j] = possib_tab[j + 1];
				possib_tab[j + 1] = tmp;
				tmp = pos_tab[j];
				pos_tab[j] = pos_tab[j + 1];
				pos_tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
