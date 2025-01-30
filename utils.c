/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:11:13 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 10:59:04 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(t_list_node *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list_node	*get_max_node(t_list_node *lst)
{
	t_list_node	*max_node;
	long		max;

	if (!lst)
		return (NULL);
	max = LONG_MIN;
	while (lst)
	{
		if (lst->nbr > max)
		{
			max = lst->nbr;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_list_node	*get_min_node(t_list_node *lst)
{
	t_list_node	*min_node;
	long		min;

	if (!lst)
		return (NULL);
	min = LONG_MAX;
	while (lst)
	{
		if (lst->nbr < min)
		{
			min = lst->nbr;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}

t_list_node	*get_list_end(t_list_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list_node	*get_list_before_end(t_list_node *lst)
{
	while (lst && lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}
