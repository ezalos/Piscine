/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 20:47:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/09/20 17:59:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list		*head;

	if (!(head = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	head->next = NULL;
	head->data = data;
	return (head);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*end;

	if (!(end = (*begin_list)->next))
		(*begin_list)->next = ft_create_elem(data);
	else
	{
		while (end->next != NULL)
			end = end->next;
		(*begin_list)->next = ft_create_elem(data);
	}
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*save;

	save = (*begin_list)->next;
	(*begin_list)->next = ft_create_elem(data);
	(*begin_list)->next->next = save;
}

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*end;

	i = 1;
	end = begin_list->next;
	while (end->next != NULL)
	{
		end = end->next;
		i++;
	}
	return (i);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*end;

	if (!(end = begin_list->next))
		return (begin_list);
	else
		while (end->next != NULL)
			end = end->next;
	return (end);
}
