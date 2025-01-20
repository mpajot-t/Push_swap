/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:11:13 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 10:35:45 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(c_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return(0);
	while (list != NULL)
		i++;
	return(i);
}

c_list	*get_max_node(c_list *lst)
{
	c_list *temp;
	int min;

	if (lst == NULL)
		return (NULL);
	min = INT_MIN;
	while (lst)
	{
		if (lst->nbr > min)
		{
			min = lst->nbr;
			temp = lst;
		}
		lst = lst->next;
	}
	return (temp);
}

c_list	*get_min_node(c_list *lst)
{
	c_list *temp;
	int min;

	if (lst == NULL)
		return (NULL);
	min = INT_MAX;
	while (lst)
	{
		if (lst->nbr < min)
		{
			min = lst->nbr;
			temp = lst;
		}
		lst = lst->next;
	}
	return (temp);
}

c_list	*get_list_end(c_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
