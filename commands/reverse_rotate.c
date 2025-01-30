/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:46:21 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 11:00:14 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_list_node **lst)
{
	t_list_node	*end;

	if (!*lst || !(*lst)->next)
		return ;
	end = get_list_end(*lst);
	end->prev->next = NULL;
	end->next = *lst;
	end->prev = NULL;
	*lst = end;
	end->next->prev = end;
}

void	rra(t_list_node **lst)
{
	reverse_rotate(lst);
	ft_printf("rra\n");
}

void	rrb(t_list_node **lst)
{
	reverse_rotate(lst);
	ft_printf("rrb\n");
}

void	rrr(t_list_node **a, t_list_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
