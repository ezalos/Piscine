/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:11:13 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/19 20:31:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		addition(int x, int y);
int		soustraction(int x, int y);
int		multiplication(int x, int y);
int		division(int x, int y);
int		modulo(int x, int y);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif
