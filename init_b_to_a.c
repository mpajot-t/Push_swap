/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:03:02 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/24 10:41:11 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(c_list *a, c_list*b)
{
	c_list	*current_a;
	c_list	*target_node;
	long	best_match_index;

	while (b)
	{
		ft_printf("Processing node in B: %d\n", b->nbr);
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = get_min_node(a);
		else
			b->target_node = target_node;
		ft_printf("Node in B: %d -> Target: %d\n", b->nbr, b->target_node->nbr);
		b = b->next;
	}
}

void	init_nodes_b(c_list *a, c_list *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}