/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:08:13 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/10 10:48:54 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(c_list **list, int n)
{
	c_list	*node;
	c_list	*last_node;

	if (!list)
		return ;
	node = malloc(sizeof(c_list));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*list))
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_list_end(*list);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_list_a(c_list **list, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_format(argv[i]))
			lstclear(list);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			lstclear(list);
		if (error_dup(*list, n))
			lstclear(list);
		append_node(list, n);
		i++;
	}
}
