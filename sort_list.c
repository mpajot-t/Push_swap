/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:24:35 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/24 10:37:53 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(c_list **a, c_list **b, c_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(c_list **a, c_list **b, c_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(c_list **a, c_list **b)
{
	c_list	*cheapest_node;

	cheapest_node = get_min_node(*a);
	ft_printf("Cheapest node: %d, Target node: %d\n", cheapest_node->nbr, cheapest_node->target_node->nbr);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

static void	move_b_to_a(c_list **a, c_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
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
		pb(a, b);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !check_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
		print_stack(*a, "A");
		print_stack(*b, "B");
	}
	sort_three(a);
	print_stack(*a, "A");
	print_stack(*b, "B");
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
