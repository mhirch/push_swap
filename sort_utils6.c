/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:32:16 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/16 16:21:58 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case4(t_list **a, t_list **b, int *move_a, int *move_b)
{
	(*move_b) = (*move_b) - (*move_a);
	while ((*move_a) < 0)
	{
		make_operation("rrr", a, b);
		(*move_a)++;
	}
}

void	case5(t_list **a, t_list **b, int *move_a, int *move_b)
{
	(*move_a) = (*move_a) - (*move_b);
	while ((*move_b) < 0)
	{
		make_operation("rrr", a, b);
		(*move_b)++;
	}
}

void	case6(t_list **a, t_list **b, int *move_a, int *move_b)
{
	while ((*move_a) < 0)
	{
		make_operation("rrr", a, b);
		(*move_a)++;
		(*move_b)++;
	}
}

int is_lis_in_stack(t_list *a, t_lis_info *lis)
{
	int i;

	i = 0;
	while (i < lis->length_lis)
	{
		if (lis->lis[i] == a->data)
			return (1);
		i++;
	}
	return (0);
}
