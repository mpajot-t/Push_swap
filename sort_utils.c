/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:46 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/14 10:13:12 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(c_list *lst)
{
	if(!lst)
		return (NULL);
	while(lst->next)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst->next;
	}
	return (1);
}

void	sort_three(c_list **a)
{
	c_list *biggest_node;

	biggest_node = get_max_node(*a);
	if (biggest_node == (*a)->nbr)
		rotate(a);
	else if ((*a)->next == biggest_node)
		reverse_rotate(a);
	if ((*a)->nbr > (*a)->next->nbr)
		swap(*a);
}