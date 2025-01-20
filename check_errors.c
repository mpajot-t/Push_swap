/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:12 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 10:22:33 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_dup(c_list *list, int nb)
{
	int	i;

	i = 0;
	while(list != NULL)
	{
		if(list->nbr == nb)
			i++;
	}
	if (i >= 2)
		return (0);
	else
		return (1);
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
	c_list *current;

	if (!lst)
		return ;
	current = *lst;
	while (*lst)
	{
		temp = (current)->next;
		current->nbr = 0;
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