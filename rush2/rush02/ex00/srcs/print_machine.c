/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:59:57 by brichard          #+#    #+#             */
/*   Updated: 2018/09/16 21:45:18 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char str)
{
	write(1, &str, 1);
}

void	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int		error(void)
{
	ft_putstr("aucune");
	return (0);
}
