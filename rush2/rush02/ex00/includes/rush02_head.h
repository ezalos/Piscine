/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_head.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:55:20 by brichard          #+#    #+#             */
/*   Updated: 2018/09/16 22:33:46 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_HEAD_H
# define RUSH02_HEAD_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

void	ft_print(int o, int y, int x);
void	ft_brain(char **tab);
char	**ft_split(char *str);
char	*ft_strdup_add_one(char *src, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(long nb);
int		error(void);
char	*read_file(void);
void	ft_check_00(char **big, int y, int x, int o);
int		rush0x(char **big, char tab[3][3], int y, int x);
int		word_counter(char *s, char c);

#endif
