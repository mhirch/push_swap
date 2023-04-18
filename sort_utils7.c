/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:50 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/18 17:44:07 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	akhir_sort(t_list **a, t_list **b)
{
	int	position;

	position = find_position(*a, smallest_in_stack(*a));
	while (position != 0)
	{
		if (position >= length(*a))
			make_operation("rra", a, b);
		if (position < length(*a))
			make_operation("ra", a, b);
		position = find_position(*a, smallest_in_stack(*a));
	}
}

int	check_moves(t_list *a, t_list *b, int **moves)
{
	t_list	*temp_b;
	int		i;

	i = 0;
	temp_b = b;
	while (temp_b)
	{
		moves[i++] = calcul_moves(a, b, temp_b->data);
		temp_b = temp_b->next;
	}
	return (i);
}
