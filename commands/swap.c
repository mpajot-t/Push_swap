/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:43:50 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 11:00:28 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_list_node	**lst)
{
	if (!lst || !(*lst)->next)
		return ;
	*lst = (*lst)->next;
	(*lst)->prev->prev = *lst;
	(*lst)->prev->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	(*lst)->next = (*lst)->prev;
	(*lst)->prev = NULL;
}

void	sa(t_list_node **lst)
{
	swap(lst);
	ft_printf("sa\n");
}

void	sb(t_list_node **lst)
{
	swap(lst);
	ft_printf("sb\n");
}

void	ss(t_list_node **a, t_list_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
