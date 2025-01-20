/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:24:35 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 10:39:16 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(c_list **a, c_list **b)
{
	c_list	*cheapest_node;

	cheapest_node = get_min_node(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rr(a, b);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rrr(a, b);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push(b, a);
}

static void	move_b_to_a(c_list **a, c_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	push(a, b);
}

static void	min_on_top(c_list **a)
{
	while ((*a)->nbr != get_min_node(*a)->nbr)
	{
		if (get_min_node(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_list(c_list **a, c_list **b)
{
	int	len_a;

	len_a = lst_len(*a);
	if (len_a-- > 3 && !check_sorted(*a))
		push(b, a);
	if (len_a-- > 3 && !check_sorted(*a))
		push(b, a);
	while (len_a-- > 3 && !check_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}