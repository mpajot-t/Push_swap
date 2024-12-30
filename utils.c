/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:11:13 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/18 10:38:32 by mpajot-t         ###   ########.fr       */
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

int	get_max_node(c_list *list)
{
	c_list *temp;
	int max;

	if (list == NULL)
		return (NULL);
	temp = list;
	max = INT_MIN;
	while (temp != NULL)
	{
		if (temp->nbr > max)
			max = temp->nbr;
		temp->next;
	}
	return (max);
}

int	get_min_node(c_list *list)
{
	c_list *temp;
	int min;

	if (list == NULL)
		return (NULL);
	temp = list;
	min = INT_MAX;
	while (temp != NULL)
	{
		if (temp->nbr < min)
			min = temp->nbr;
		temp->next;
	}
	return (min);
}
