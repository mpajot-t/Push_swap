/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:12 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/22 10:52:33 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_dup(c_list *list, int nb)
{
	if (!list)
		return (0);
	while(list)
	{
		if(list->nbr == nb)
			return (1);
		list = list->next;
	}
	return (0);
}

int	error_format(char *c)
{
	int	i;

	i = 0;
	while(c[i])
	{
		if (c[i] <= 47 || c[i] >= 58 || c[i] != '+' || c[i] != '-')
			return (0);
	}
	return (1);
}

void	free_lst(c_list **lst)
{
	c_list	*temp;
	c_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		current->next = NULL;
		current->prev = NULL;
		current->target_node = NULL;  // Important!
		current->nbr = 0;
		current->index = 0;
		current->push_cost = 0;
		current->above_median = false;
		current->cheapest = false;
		free(current);
		current = temp;
	}
	*lst = NULL;
}

void	free_errors(c_list **a)
{
	free_lst(a);
	ft_printf("Error\n");
	exit(1);
}