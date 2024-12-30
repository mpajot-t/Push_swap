/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:50:14 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/18 10:07:48 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	c_list *list_a;
	c_list *list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2 || argc == 2 && argv[1][0] == "\0")
		ft_printf("Error/n");
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_list_a(list_a, argv + 1);
	if (!check_sorted(list_a))
	{
		if (lst_len(list_a) == 2)
			sa(&list_a);
		else if (lst_len == 3)
			sort_three(&list_a);
		else
			sort_lists(&list_a, &list_b);
	}
	free_list(&list_a);
	return (0);
}