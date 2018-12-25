/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:52:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/16 23:38:37 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		in_error(void)
{
	ft_putstr("aucune\n");
	return (0);
}

int		main(void)
{
	char	**big;
	char	*str;
	int		o;
	int		i;

	big = NULL;
	str = NULL;
	i = -1;
	o = 0;
	str = read_file();
	if (str == NULL || str[0] == '\n' || str[ft_strlen(str) - 1] != '\n')
		return (in_error());
	while (str[++i + 1])
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (in_error());
	i = 0;
	big = ft_split(str);
	if (!(o = ft_strlen(big[i])))
		return (in_error());
	while (big[i])
		if (o != ft_strlen(big[i++]))
			return (in_error());
	ft_brain(big);
	return (0);
}
