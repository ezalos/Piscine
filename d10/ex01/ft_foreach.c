/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:54:46 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/19 17:45:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr(int nb)
{
	int	i;
	i = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		i++;
		return ;
	}
	if (nb < 0 && i == 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (i == 0)
	{
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar(nb + '0');
	}
}

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int i;

	i = 0;
	while (i < length)
	{
		f(tab[i++]);
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	void (*f)(int);
	int *tab;
	int i;

	f = &ft_putnbr;
	if (!(tab = (int*)malloc(argc * sizeof(int))))
		return (0);

	i = 0;
	while (i < argc - 1)
	{
		tab[i] = atoi(argv[i + 1]);
		i++;
	}

	ft_foreach(tab, argc - 1, f);
}
