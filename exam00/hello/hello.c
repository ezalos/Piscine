/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 18:31:55 by exam              #+#    #+#             */
/*   Updated: 2018/08/31 18:43:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void hello(void)
{
	write(1,"H",1);	
	write(1,"e",1);	
	write(1,"l",1);	
	write(1,"l",1);	
	write(1,"o",1);	
	write(1," ",1);	
	write(1,"W",1);	
	write(1,"o",1);	
	write(1,"r",1);	
	write(1,"l",1);	
	write(1,"d",1);	
	write(1,"!",1);	
	write(1,"\n",1);	
}

int main()
{
	hello();
	return(0);
}
