/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 20:30:39 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/19 20:31:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do-op.h"

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

int		ft_atoi(char *str)
{
	int			i;
	long long	nb;
	int			nb_return;

	i = 0;
	nb = 0;
	nb_return = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= 57 && str[i] >= 48)
	{
		nb = (str[i] - '0') + nb * 10;
		i++;
	}
	if (str[0] == '-')
		nb = -1 * nb;
	if (-2147483648 <= nb && nb <= 2147483647)
		nb_return = nb;
	return (nb_return);
}
