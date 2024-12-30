/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:50:11 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/18 10:38:08 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "printf/ft_printf.h"
# include <stdio.h>
# include <limits.h>
typedef struct t_list
{
	int nbr;
	int index;
	struct t_list *next;
	struct t_list *prev;
} c_list;
int	check_sorted(c_list *list);
void	init_list_a(c_list **list, char **argv);
int	error_dup(c_list *list, int nb);
int	error_format(char *c);
int	lst_len(c_list *list);
int	get_max_node(c_list *list);
int	get_min_node(c_list *list);

#endif