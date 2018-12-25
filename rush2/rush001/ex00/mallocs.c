/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:46:49 by jbarment          #+#    #+#             */
/*   Updated: 2018/09/09 21:47:23 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*malloc_81(void)
{
	int	i;
	int	*pos_tab;

	i = 0;
	if (malloc(sizeof(int) * 162))
	{
		pos_tab = (int*)(malloc(sizeof(int) * 81));
	}
	else
	{
		pos_tab = 0;
	}
	return (pos_tab);
}

char	**malloc_9x9(void)
{
	int		i;
	char	**tab;

	i = 0;
	if (malloc(sizeof(char*) * 9))
	{
		tab = (char**)(malloc(sizeof(char*) * 9));
		while (i < 9)
		{
			if (malloc(sizeof(char) * 9))
			{
				tab[i] = (char*)(malloc(sizeof(char) * 9));
			}
			else
				tab[i] = 0;
			i++;
		}
	}
	else
	{
		tab = 0;
	}
	return (tab);
}

char	**malloc_9x10(void)
{
	int		i;
	char	**solution;

	i = 0;
	if (malloc(sizeof(char*) * 9))
	{
		solution = (char**)(malloc(sizeof(char*) * 9));
		while (i < 9)
		{
			if (malloc(sizeof(char) * 10))
			{
				solution[i] = (char*)(malloc(sizeof(char) * 10));
			}
			i++;
		}
	}
	else
	{
		solution = 0;
	}
	return (solution);
}

void	free_all(char **tab, int *possib_tab, int *pos_tab, char **solution)
{
	int	i;

	i = 0;
	free(possib_tab);
	free(pos_tab);
	while (i < 9)
	{
		free(solution[i]);
		free(tab[i]);
		i++;
	}
	free(solution);
	free(tab);
}
