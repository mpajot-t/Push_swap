/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:43:50 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 10:44:54 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(c_list *lst)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->nbr;
	lst->nbr = lst->next->nbr;
	lst->next->nbr = temp;
	ft_printf("sa\n");
}

void	sb(c_list *lst)
{
	int	temp;

	if (lst == NULL || lst->next == NULL)
		return ;
	temp = lst->nbr;
	lst->nbr = lst->next->nbr;
	lst->next->nbr = temp;
	ft_printf("sb\n");
}

void	ss(c_list **a, c_list **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}