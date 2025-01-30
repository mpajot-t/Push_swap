/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:50:11 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/30 11:06:02 by mpajot-t         ###   ########.fr       */
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
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct t_list	*target_node;
	struct t_list	*next;
	struct t_list	*prev;
}	t_list_node;

//List utils
t_list_node	*get_list_end(t_list_node *lst);
t_list_node	*get_list_before_end(t_list_node *lst);
t_list_node	*get_cheapest(t_list_node *lst);
t_list_node	*get_max_node(t_list_node *lst);
t_list_node	*get_min_node(t_list_node *lst);

//Utils
bool		check_sorted(t_list_node *lst);
int			lst_len(t_list_node *lst);
char		**split(char *s, char c);
void		print_stack(t_list_node *stack, char *name);

//Handle errors
void		free_lst(t_list_node **lst);
int			error_dup(t_list_node *list, int nb);
int			error_format(char *c);
void		free_errors(t_list_node **a);
void		lstclear(t_list_node **lst);

//Algo
void		init_list_a(t_list_node **list, char **argv);
void		prep_for_push(t_list_node **lst,
				t_list_node *top_node, char lst_name);
void		sort_three(t_list_node **a);
void		current_index(t_list_node *lst);
void		init_nodes_a(t_list_node *a, t_list_node *b);
void		set_cheapest(t_list_node *lst);
void		sort_list(t_list_node **a, t_list_node **b);
void		init_nodes_b(t_list_node *a, t_list_node *b);

// Commands
void		pa(t_list_node **src, t_list_node **dest);
void		pb(t_list_node **src, t_list_node **dest);
void		rra(t_list_node **lst);
void		rrb(t_list_node **lst);
void		rrr(t_list_node **a, t_list_node **b);
void		ra(t_list_node **lst);
void		rb(t_list_node **lst);
void		rr(t_list_node **a, t_list_node **b);
void		sa(t_list_node **lst);
void		sb(t_list_node **lst);
void		ss(t_list_node **a, t_list_node **b);

#endif