/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 18:10:13 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 18:25:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void only_a(void)
{
	char a;
	a = 'a';
	write(1 , &a , 1 );
}

int main()
{
	only_a();
	return(0);
}
