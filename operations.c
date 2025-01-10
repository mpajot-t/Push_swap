/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:47:00 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/09 10:34:34 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(c_list *lst)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->nbr;
	lst->nbr = lst->next->nbr;
	lst->next->nbr = temp;
}

void	ss(c_list **a, c_list **b)
{
	swap(*a);
	swap(*b);
}

void	push(c_list **src, c_list **dest)
{
	c_list	*temp;

	if	(!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*dest = temp;
}

void	rotate(c_list **a)
{
	c_list	*temp;
	c_list	*end;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	end = get_list_end(*a);
	temp->next = NULL;
	end->next = temp;
}

void	rr(c_list *a, c_list *b)
{
	
}