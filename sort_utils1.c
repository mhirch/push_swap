/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:51:19 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/17 18:27:19 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_index(t_lis_info *lis, t_info *a)
{
	int	i;
	int	j;

	i = 1;
	while (i < a->capacity)
	{
		j = 0;
		while (j < i)
		{	
			if (a->arr[j] < a->arr[i] && lis->length[i] <= lis->length[j] + 1)
			{
				lis->length[i] = lis->length[j] + 1;
				lis->index_of_lis[i] = j;
			}
			j++;
		}
		if (lis->length[i] > lis->length_lis)
		{
			lis->length_lis = lis->length[i];
			lis->max_lis_index = i;
		}
		i++;
	}
	i = 0;
}

void get_lis(t_lis_info *lis, t_info *a)
{
	int current_index;
	int current_value;
	
	// lis->lis = malloc(lis->length_lis * sizeof(int));
	current_index = lis->length_lis - 1;
	current_value = a->arr[lis->max_lis_index];
	while (current_index >= 0)
	{
		lis->lis[current_index] = current_value;
		current_index--;
		current_value = a->arr[lis->index_of_lis[lis->max_lis_index]];
		lis->max_lis_index = lis->index_of_lis[lis->max_lis_index];
	}
}

t_lis_info *initialize_lis(int a)
{
	int j;
	t_lis_info *lis;
	
	lis = malloc(sizeof(t_lis_info));
	lis->length_lis = 0;
	lis->max_lis_index = 0;
	lis->length = malloc(a * sizeof(int));
	lis->index_of_lis = malloc(a * sizeof(int));
	lis->lis = malloc(lis->length_lis * sizeof(int));
	j = 0;
	while( j < a)
	{
		lis->length[j] = 1;
		lis->index_of_lis[j++] = -1;
	}
	return(lis);
}

void	out_of_lis_in_b(t_list **a, t_list **b, t_lis_info *lis, int capacity)
{
	while (capacity-- > 0)
	{
		if (is_lis_in_stack(*a, lis) == 1)
			make_operation("ra", a, b);
		if (is_lis_in_stack(*a, lis) == 0)
			make_operation("pb", a, b);
	}
}

void	magic(t_list **b,t_list **a)
{
	t_list *temp_b;
	int **moves;
	int i,j;
	int index;
	int position = 0;
	moves = malloc(sizeof(int *) * length(*b));
	while (*b)
	{
		i = 0;
		temp_b = *b;
		while(temp_b)
		{
			moves[i++] = calcul_moves(*a, *b, temp_b->data);
			temp_b = temp_b->next;
		}
		index = best_one(moves, length(*b));
		better_call_saul(a, b, moves[index]);
		j = -1;
		while (++j < i)
			free(moves[j]);
	}
	free(moves);
	position = find_position(*a, smallest_in_stack(*a));
	while (position != 1)
	{
		position = find_position(*a, smallest_in_stack(*a));
		if ( position >= length(*a))
			make_operation("rra", a, b);
		if ( position < length(*a))
		make_operation("ra", a, b);
	}
}