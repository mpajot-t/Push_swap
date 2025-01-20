/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:42:25 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 10:43:24 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(c_list **src, c_list **dest)
{
	c_list	*temp;

	if	(!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*dest = temp;
	ft_printf("pa\n");
}

void	pb(c_list **src, c_list **dest)
{
	c_list	*temp;

	if	(!*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*dest = temp;
	ft_printf("pb\n");
}