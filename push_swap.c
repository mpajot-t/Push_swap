/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:50:14 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/20 11:04:21 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	c_list	*a;
	c_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || argc == 2 && argv[1][0] == "\0")
		ft_printf("Error/n");
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_list_a(&a, argv + 1);
	if (!check_sorted(a))
	{
		if (lst_len(a) == 2)
			sa(&a);
		else if (lst_len == 3)
			sort_three(&a);
		else
			sort_lists(&a, &b);
	}
	free_list(&a);
	return (0);
}