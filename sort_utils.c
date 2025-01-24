/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:46 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/23 10:36:30 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(c_list *stack, char *name) 
{
	ft_printf("%s stack: ", name);
	while (stack) {
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}

bool	check_sorted(c_list *lst)
{
	if(!lst)
		return (1);
	while(lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (false);
		lst = lst->next;
	}
	return (true);
}

void	sort_three(c_list **a)
{
	c_list *biggest_node;

	biggest_node = get_max_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}