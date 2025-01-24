/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:46:21 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/24 10:43:59 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(c_list **a)
{
	c_list	*end;

	end = get_list_end(*a);
	ft_printf("End node before reverse rotation a: %d\n", end->nbr);
	end->prev->next = NULL;
	end->next = *a;
	end->prev = NULL;
	*a = end;
	end->next->prev = end;
	ft_printf("New head after rra: %d\n", (*a)->nbr);
	ft_printf("rra\n");
}

void	rrb(c_list **a)
{
	c_list	*end;

	end = get_list_end(*a);
	ft_printf("End node before reverse rotation b: %d\n", end->nbr);
	end->prev->next = NULL;
	end->next = *a;
	end->prev = NULL;
	*a = end;
	end->next->prev = end;
	ft_printf("New head after rrb: %d\n", (*a)->nbr);
	ft_printf("rrb\n");
}

void	rrr(c_list **a, c_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}