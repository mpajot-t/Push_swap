/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:43:50 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/22 10:34:48 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(c_list **lst)
{
	if (!lst || !(*lst)->next)
		return ;
	*lst = (*lst)->next;
	(*lst)->prev->prev = *lst;
	(*lst)->prev->prev = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	(*lst)->next = (*lst)->prev;
	(*lst)->prev = NULL;
	ft_printf("sa\n");
}

void	sb(c_list **lst)
{
	if (!lst || !(*lst)->next)
		return ;
	*lst = (*lst)->next;
	(*lst)->prev->prev = *lst;
	(*lst)->prev->prev = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	(*lst)->next = (*lst)->prev;
	(*lst)->prev = NULL;
	ft_printf("sb\n");
}

void	ss(c_list **a, c_list **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}