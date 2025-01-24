/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:50:11 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/23 10:36:44 by mpajot-t         ###   ########.fr       */
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

//List utils
c_list	*get_list_end(c_list *lst);
c_list	*get_list_before_end(c_list *lst);
c_list	*get_cheapest(c_list *lst);
c_list	*get_max_node(c_list *lst);
c_list	*get_min_node(c_list *lst);

//Handle errors
void	free_lst(c_list **lst);
int	error_dup(c_list *list, int nb);
int	error_format(char *c);
void	free_errors(c_list **a);

//...
void	init_list_a(c_list **list, char **argv);
bool	check_sorted(c_list *lst);
void	lstclear(c_list **lst);
int	lst_len(c_list *lst);
char	**split(char *s, char c);
void	print_stack(c_list *stack, char *name);

// Commands
void	pa(c_list **src, c_list **dest);
void	pb(c_list **src, c_list **dest);
void	rra(c_list **a);
void	rrb(c_list **a);
void	rrr(c_list **a, c_list **b);
void	ra(c_list **a);
void	rb(c_list **a);
void	rr(c_list **a, c_list **b);
void	sa(c_list **lst);
void	sb(c_list **lst);
void	ss(c_list **a, c_list **b);

void	sort_three(c_list **a);
void	current_index(c_list *lst);
void	init_nodes_a(c_list *a, c_list *b);
void	set_cheapest(c_list *lst);
void	sort_list(c_list **a, c_list **b);
void	init_nodes_b(c_list *a, c_list *b);
void	prep_for_push(c_list **lst, c_list *top_node, char lst_name);
#endif