/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:53:02 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/18 21:44:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

void	ft_copy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

char	*read_file(void)
{
	char	*str;
	char	*tmp;
	int		i;
	char	c;

	i = 0;
	tmp = NULL;
	str = NULL;
	while (read(0, &c, 1) > 0)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (i + 2))))
			return (NULL);
		if (str)
			ft_copy(tmp, str);
		if (str)
			free(str);
		tmp[i] = c;
		tmp[i + 1] = '\0';
		if (!(str = (char *)malloc(sizeof(char) * (i++ + 2))))
			return (NULL);
		ft_copy(str, tmp);
		if (tmp)
			free(tmp);
	}
	return (str);
}
