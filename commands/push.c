/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:42:25 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/24 10:42:10 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(c_list **src, c_list **dest)
{
	c_list	*push_node;

	if (!src || !*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	ft_printf("Pushing node %d from src to dest\n", push_node->nbr);
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		(*dest)->prev = push_node;
		*dest = push_node;
	}
	ft_printf("pa\n");
}

void	pb(c_list **src, c_list **dest)
{
	c_list	*push_node;

	if (!src || !*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		(*dest)->prev = push_node;
		*dest = push_node;
	}
	ft_printf("pb\n");
}