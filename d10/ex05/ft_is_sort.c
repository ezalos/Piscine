/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:18:55 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/19 18:28:16 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
   int		ft_is_sort(int *tab, int length, int(*f)(int, int))
   {
   int i;
   int j;
   int save;

   j = 0;
   while (tab[++j])
   {
   i = 0;
   while (tab[++i])
   if (f(tab[i-1], [i]) > 0)
   {
   save = tab[i - 1];
   tab[i - 1] = tab[i];
   tab[i] = save;
   }
   }
   return (tab)
   }*/

int		ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;

	i = 0;
	while (++i < length)
		if ((f(tab[i-1], tab[i])) > 0)
			return (0);
		return (1);
}
