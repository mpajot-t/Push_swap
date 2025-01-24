/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:11 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/24 10:44:59 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(c_list **a)
{
	c_list	*last_node;

	if (!*a || !(*a)->next)
		return ;
	last_node = get_list_end(*a);
	ft_printf("End node before rotation a: %d\n", last_node->nbr);
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	ft_printf("New head after ra: %d\n", (*a)->nbr);
	ft_printf("ra\n");
}

void	rb(c_list **a)
{
	c_list	*last_node;

	if (!*a || !(*a)->next)
		return ;
	last_node = get_list_end(*a);
	ft_printf("End node before rotation b: %d\n", last_node->nbr);
	last_node->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	ft_printf("New head after rb: %d\n", (*a)->nbr);
	ft_printf("rb\n");
}

void	rr(c_list **a, c_list **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}