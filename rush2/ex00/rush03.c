/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:30:39 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/03 20:56:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char lettre);

void	ligne1(int longueur)
{
	int sx;

	sx = 0;
	if (longueur == 1)
		sx = 1;
	ft_putchar('A');
	while (longueur > 2)
	{
		longueur--;
		ft_putchar('B');
	}
	if (sx == 0)
		ft_putchar('C');
}

void	ligne2(int longueur)
{
	int sx;

	sx = 0;
	if (longueur == 1)
		sx = 1;
	ft_putchar('B');
	while (longueur > 2)
	{
		ft_putchar(' ');
		longueur--;
	}
	if (sx == 0)
		ft_putchar('B');
}

void	ligne3(int longueur)
{
	int sx;

	sx = 0;
	if (longueur == 1)	//Gestion du cas particulier d'un seul caractere avec une variable
		sx = 1;
	ft_putchar('A');  //PREMIER CARACTERE (pas de condition car tjrs imprime)
	while (longueur > 2)  // CARACTERE MILIEU (superieur a 2 car premier pa sosustrait et dernier a prevoir
	{
		longueur--;
		ft_putchar('B');
	}
	if (sx == 0)
		ft_putchar('C');
}

void	ligne(int longueur, int position)
{
	if (position == 0)  // PREMIERE ligne
		ligne1(longueur);
	else if (position == 1) // MILIEU ligne
		ligne2(longueur);
	else if (position == 2) // DERNIERE ligne
		ligne3(longueur);
	ft_putchar('\n');
}

void	rush(int x, int y) // LA OUTOUT COMMENCE (seule fonction appelee par le main)
{
	int sy;

	sy = 0;
	if (y == 1)  // CAS PARTICULIER Sy=2
		sy = 1;
	if (x > 0 && y > 0)  //EST CE QUE LE CARRE EXISTE ?
	{
		ligne(x, 0);  //DEBUT pas de if, car on imprime tjrs la premiere ligne
		y--;
		while (y > 1) // MILIEU  on veut y>1 car on si y=2 pas d'impression de la ligne du milieu
		{
			ligne(x, 1);
			y--;
		}
		if (sy == 0)  // Si la variable (sy) du Cas particlier (afficher une seule ligne)  est OFF on rentre
			ligne(x, 2); // DERNIERE 
	}
}
