/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:46 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/01/10 10:59:07 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(c_list *lst)
{
	if(!lst)
		return (NULL);
	while(lst)
	{
		if (lst->nbr > lst->next->nbr)
			return (0);
		lst->next;
	}
	return (1);
}