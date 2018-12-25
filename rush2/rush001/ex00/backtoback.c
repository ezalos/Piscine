/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtoback.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:09:28 by jbarment          #+#    #+#             */
/*   Updated: 2018/09/09 23:35:04 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	free_all(char **tab, int *possib_tab, int *pos_tab, char **solution);
void	ft_print_grid(char **solution);
int		ft_find(char **tab, int *pos_tab, int walker, char **solution);
void	ft_order_tab(int *possib_tab, int *pos_tab);
void	ft_fill_tab(char **tab, int *pos_tab, int *possib_tab);
void	copy_solution(char **tab, char **solution);
int		*malloc_81(void);
char	**malloc_9x9(void);
char	**malloc_9x10(void);
void	fill_sudoku(char **argv, char **tab);
int		is_ok(char **tab, char value, int pos);
int		input_check(int argc, char **argv);
int		input_check_2(char **tab);

int		ft_found_a_solution(char **tab, char **solution)
{
	copy_solution(tab, solution);
	return (0);
}

int		ft_find(char **tab, int *pos_tab, int walker, char **solution)
{
	char	value;
	int		line;
	int		col;

	value = '1';
	line = pos_tab[walker] / 9;
	col = pos_tab[walker] % 9;
	if (pos_tab[walker] == 81)
		return (ft_found_a_solution(tab, solution));
	if (tab[line][col] > '0')
		return (ft_find(tab, pos_tab, walker + 1, solution));
	while (value <= '9')
	{
		if (is_ok(tab, value, pos_tab[walker]))
		{
			tab[line][col] = value;
			if (ft_find(tab, pos_tab, walker + 1, solution))
				return (1);
		}
		value++;
	}
	tab[line][col] = 0;
	return (0);
}

int		print_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	char	**tab;
	char	**solution;
	int		*pos_tab;
	int		*possib_tab;

	if (input_check(argc, argv) == 0)
		return (print_error());
	pos_tab = malloc_81();
	possib_tab = malloc_81();
	tab = malloc_9x9();
	solution = malloc_9x10();
	solution[0][9] = 0;
	fill_sudoku(argv, tab);
	if (input_check_2(tab) == 0)
		return (print_error());
	ft_fill_tab(tab, pos_tab, possib_tab);
	ft_order_tab(pos_tab, possib_tab);
	ft_find(tab, pos_tab, 0, solution);
	ft_print_grid(solution);
	free_all(tab, possib_tab, pos_tab, solution);
	return (0);
}
