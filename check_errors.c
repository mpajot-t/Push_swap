/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:12 by mpajot-t          #+#    #+#             */
/*   Updated: 2024/12/17 11:05:45 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_dup(c_list *list, int nb)
{
	int	i;

	i = 0;
	while(list != NULL)
	{
		if(list->data == nb)
			i++;
	}
	if (i >= 2)
		return (0);
	else
		return (1);
}

int	error_format(char *c)
{
	int	i;

	i = 0;
	while(c[i])
	{
		if (c[i] >= 65 && c[i] <= 90 || c[i] >= 97 && c[i] <= 122)
			return (0);
	}
	return (1);
}