/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:08:13 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/18 10:58:11 by mpajot-t         ###   ########.fr       */
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

void	append_node(t_list_node **list, int n)
{
	t_list_node	*node;
	t_list_node	*last_node;

	if (!list)
		return ;
	node = malloc(sizeof(t_list_node));
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

void	init_list_a(t_list_node **list, char **argv, int argc)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (error_format(argv[i]))
			free_errors(list, argv, argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(list, argv, argc);
		if (error_dup(*list, (int)n))
			free_errors(list, argv, argc);
		append_node(list, (int)n);
		i++;
	}
}

t_list_node	*get_cheapest(t_list_node *lst)
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

void	prep_for_push(t_list_node **lst, t_list_node *top_node, char lst_name)
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
