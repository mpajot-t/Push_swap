/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:46:21 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 10:47:13 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(c_list **a)
{
	c_list	*temp;
	c_list	*end;
	c_list	*before_end;

	end = get_list_end(*a);
	before_end = get_list_before_end(*a);
	temp = *a;
	*a = end;
	(*a)->next = temp;
	before_end->next = NULL;
	ft_printf("rra\n");
}

void	rrb(c_list **a)
{
	c_list	*temp;
	c_list	*end;
	c_list	*before_end;

	end = get_list_end(*a);
	before_end = get_list_before_end(*a);
	temp = *a;
	*a = end;
	(*a)->next = temp;
	before_end->next = NULL;
	ft_printf("rrb\n");
}

void	rrr(c_list **a, c_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}