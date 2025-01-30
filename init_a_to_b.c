/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:41:20 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 10:48:45 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_list_node *lst)
{
	int	i;
	int	median;

	i = 0;
	if (!lst)
		return ;
	median = lst_len(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (i <= median)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst = lst->next;
		i++;
	}
}

static void	set_target_a(t_list_node *a, t_list_node *b)
{
	t_list_node	*current_b;
	t_list_node	*target_node;
	long		best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = get_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_list_node *a, t_list_node *b)
{
	int	len_a;
	int	len_b;

	len_a = lst_len(a);
	len_b = lst_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_list_node *lst)
{
	long		cheapest_value;
	t_list_node	*cheapest_node;

	if (!lst)
		return ;
	cheapest_value = LONG_MAX;
	while (lst)
	{
		if (lst->push_cost < cheapest_value)
		{
			cheapest_value = lst->push_cost;
			cheapest_node = lst;
		}
		lst = lst->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_list_node *a, t_list_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
