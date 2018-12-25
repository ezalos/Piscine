/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 00:07:08 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/16 22:18:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_head.h"

int		letter_counter(char *s, char c)
{
	int		counter;

	counter = 0;
	while (*s == c)
		s++;
	while (s[counter] != c && s[counter] != '\0')
		counter++;
	return (counter);
}

char	*next_word(char *s, char c)
{
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
		s++;
	return (s);
}

char	**malloc_big(int size)
{
	char	**big;

	big = NULL;
	big = (char **)malloc((size + 1) * sizeof(char *));
	if (big == NULL)
		return (NULL);
	big[size] = NULL;
	return (big);
}

char	*malloc_small(char *s, int letters, char c)
{
	char	*small;
	int		i;

	i = 0;
	small = NULL;
	small = (char *)malloc((letters + 1) * sizeof(char));
	if (small == NULL)
		return (NULL);
	while (*s == c)
		s++;
	while (s[i] != c && s[i] != '\0')
	{
		small[i] = s[i];
		i++;
	}
	small[letters] = '\0';
	return (small);
}

char	**ft_split(char *str)
{
	char	**big;
	int		size;
	int		i;
	char	c;

	c = '\n';
	big = NULL;
	i = 0;
	size = word_counter(str, c);
	big = malloc_big(size);
	if (big == NULL)
		return (NULL);
	while (i < size)
	{
		big[i] = malloc_small(str, letter_counter(str, c), c);
		str = next_word(str, c);
		i++;
	}
	return (big);
}
