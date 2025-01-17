/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:54:53 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/13 10:45:29 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(c_list **a)
{
	c_list	*temp;
	c_list	*end;
	c_list	*before_end;

	end = get_list_end(*a);
	before_end = get_list_before_end(*a);
	temp = *a;
	*a = end;
	(*a)->next = temp;
	before_end->next = NULL;
}

void	rrr(c_list **a, c_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}