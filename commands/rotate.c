/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:11 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 11:00:17 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_list_node **lst)
{
	t_list_node	*last_node;

	if (!*lst || !(*lst)->next)
		return ;
	last_node = get_list_end(*lst);
	last_node->next = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_list_node **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	rb(t_list_node **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}

void	rr(t_list_node **a, t_list_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
