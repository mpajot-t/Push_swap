/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:03:02 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 10:59:43 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_list_node *a, t_list_node*b)
{
	t_list_node	*current_a;
	t_list_node	*target_node;
	long		best_match_index;

	while (b)
	{
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
		b = b->next;
	}
}

void	init_nodes_b(t_list_node *a, t_list_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
