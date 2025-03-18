/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:12 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/18 11:16:01 by mpajot-t         ###   ########.fr       */
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
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i + 1] == '-' || c[i + 1] == '+' || !c[i + 1])
			return (1);
		i++;
	}
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
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

void	free_errors(t_list_node **a, char **argv, int argc)
{
	free_lst(a);
	if (argc == 2)
		free_argv(argv);
	ft_printf("Error\n");
	exit(1);
}
