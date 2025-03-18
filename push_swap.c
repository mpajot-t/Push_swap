/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:50:14 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/03/18 11:08:35 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	c;

	c = 0;
	while (argv[c])
		free(argv[c++]);
	free(argv);
}

int	main(int argc, char **argv)
{
	t_list_node	*a;
	t_list_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_printf("Error/n");
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_list_a(&a, argv, argc);
	if (!check_sorted(a))
	{
		if (lst_len(a) == 2)
			sa(&a);
		else if (lst_len(a) == 3)
			sort_three(&a);
		else
			sort_list(&a, &b);
	}
	if (argc == 2)
		free_argv(argv);
	free_lst(&a);
	return (0);
}
