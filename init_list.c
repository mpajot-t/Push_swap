/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:08:13 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/21 09:46:03 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

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
	node->cheapest = 0;
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
			free_lst(list);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_lst(list);
		if (error_dup(*list, (int)n))
			free_lst(list);
		append_node(list, n);
		i++;
	}
}

c_list	*get_cheapest(c_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->cheapest)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	prep_for_push(c_list **lst, c_list *top_node, char lst_name)
{
	while (*lst != top_node)
	{
		if (lst_name == 'a')
		{
			if (top_node->above_median)
				ra(lst);
			else
				rra(lst);
		}
		else if (lst_name == 'b')
		{
			if (top_node->above_median)
				rb(lst);
			else
				rrb(lst);
		}
	}
}