/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:11:19 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/19 20:37:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do-op.h"

int		choice(char **argv, int o)
{
	if (argv[2][0] == '+' && argv[2][1] == '\0')
		o = 0;
	else if (argv[2][0] == '-' && argv[2][1] == '\0')
		o = 1;
	else if (argv[2][0] == '*' && argv[2][1] == '\0')
		o = 2;
	else if (argv[2][0] == '/' && argv[2][1] == '\0')
	{
		o = 3;
		if ( 0 == ft_atoi(argv[3]))
			return (-o);
	}
	else if (argv[2][0] == '%' && argv[2][1] == '\0')
	{
		o = 4;
		if ( 0 == ft_atoi(argv[3]))
		{
			ft_putstr("stop : modulo by zero\n");
			return (-1);
		}
	}
	return (o);
}

int		main(int argc, char **argv)
{
	int (*f[5]) (int, int);
	int i;
	int o;

	i = 0;
	f[0] = &addition;
	f[1] = &soustraction;
	f[2] = &multiplication;
	f[3] = &division;
	f[4] = &modulo;
	if (argc != 4)
		return (0);
	o = choice(argv, 5);
	if (o == 5)
		ft_putstr("0\n");
	else if ( o != -1)
	{
		ft_putnbr(f[o](ft_atoi(argv[1]), ft_atoi(argv[3])));
		ft_putchar('\n');
	}
	else if (o < 0)
		ft_putstr("stop : division by zero\n");
	return (0);
}
