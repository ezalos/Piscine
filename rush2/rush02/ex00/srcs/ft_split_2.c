/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:39:04 by brichard          #+#    #+#             */
/*   Updated: 2018/09/16 21:39:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

int		word_counter(char *s, char c)
{
	int		counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			while (*s != c && *s != '\0')
				s++;
			counter++;
		}
	}
	return (counter);
}
