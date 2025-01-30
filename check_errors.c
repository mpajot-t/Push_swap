/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:12 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 10:39:01 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_dup(t_list_node *list, int nb)
{
	if (!list)
		return (0);
	while (list)
	{
		if (list->nbr == nb)
			return (1);
		list = list->next;
	}
	return (0);
}

int	error_format(char *c)
{
	int	i;

	i = 0;
	if (!(c[i] == '+' || c[i] == '-' || (c[i] >= '0' && c[i] <= '9')))
		return (1);
	if ((c[i] == '+' || c[i] == '-') && !(c[1] >= '0' && c[1] <= '9'))
		return (1);
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_lst(t_list_node **lst)
{
	t_list_node	*temp;
	t_list_node	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*lst = NULL;
}

void	free_errors(t_list_node **a)
{
	free_lst(a);
	ft_printf("Error\n");
	exit(1);
}
