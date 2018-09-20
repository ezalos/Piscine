/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:47:49 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/19 18:09:31 by ldevelle         ###   ########.fr       */
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

int		ft_square(int i)
{
	return (i * i);
}

int		*ft_map(int *tab, int length, int(*f)(int))
{
	int i;

	i = -1;
	while (++i < length)
		tab[i] = f(tab[i]);
	return (tab);
}

int		main(int argc, char **argv)
{
	int	*(*f)(int*, int, int(*f)(int));
	int	*tab;
	int	i;

	f = &ft_map;
	i = -1;
	if (argc < 2)
		return (0);
	if (!(tab = (int*)malloc((argc - 1) * sizeof(int))))
		return (0);
	while (++i < argc - 1)
		tab[i] = atoi(argv[i + 1]);
	tab = f(tab, argc - 1, &ft_square);

	i = 0;
	while (i < argc -1)
	{
		ft_putnbr(tab[i++]);
		ft_putchar('\n');
	}
	return (0);
}
