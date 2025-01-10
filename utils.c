/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:11:13 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/10 10:46:24 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(c_list **lst)
{
	c_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

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

c_list	*get_list_end(c_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
