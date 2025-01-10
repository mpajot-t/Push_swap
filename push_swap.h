/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:50:11 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/10 11:00:04 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>
typedef struct t_list
{
	int nbr;
	int index;
	int push_cost;
	bool above_median;
	bool cheapest;
	struct t_list *target_node;
	struct t_list *next;
	struct t_list *prev;
} c_list;
int	check_sorted(c_list *list);
void	init_list_a(c_list **list, char **argv);
int	error_dup(c_list *list, int nb);
int	error_format(char *c);
int	check_sorted(c_list *lst);
void	lstclear(c_list **lst);
int	lst_len(c_list *list);
int	get_max_node(c_list *list);
int	get_min_node(c_list *list);
c_list	*get_list_end(c_list *lst);
void	swap(c_list *lst);
void	ss(c_list **a, c_list **b);
void	push(c_list **a, c_list **b);
#endif