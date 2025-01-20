/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:11 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 10:46:08 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(c_list **a)
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
	ft_printf("ra\n");
}

void	rb(c_list **a)
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
	ft_printf("rb\n");
}

void	rr(c_list **a, c_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}