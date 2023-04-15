/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:00:29 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/14 17:09:31 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	magic(t_list **b,t_list **a)
{
	t_list *temp_b;
	int **moves;
	int i;
	int index;
	int position;
	
	moves = malloc(sizeof(int *) * length(*b));
	// printList(*a);
	// printList(*b);
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
		position = find_position(*a, smallest_in_stack(*a) != (*a)->data);
		while (smallest_in_stack(*a) != (*a)->data)
		{
			if ( position >= length(*a))
				make_operation("rra", a, b);
			if ( position < length(*a))
				make_operation("ra", a, b);
		}
		/*-------------*/
		// printList(*a);
		// printList(*b);
		/*-------------*/
	}
}

int length(t_list *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	*calcul_moves(t_list *a, t_list *b, int data)
{
	t_list *temp_b;
	int *moves;
	int position;
	int i,j;

	i = 0;
	j = 0;
	moves = malloc(sizeof(int) * 2);
	temp_b = b;
	position = find_position(b, data);
	moves[0] = moves_stack_a(a, data);
		// printf("moves in A %d\n", moves[0]);
	moves[1] = moves_stack_b(b, position);
		// printf("moves in B %d\n", moves[1]);
	
	return (moves);
}

int	find_position(t_list *stack, int number)
{
	int position;

	position = 0;
	while (stack->next)
	{
		if (stack->data == number)
			break ;
		position++;
		stack = stack->next;
	}
	return (position);
}

int	data_is_biggest(t_list *a, int data)
{
	while (a)
	{
		if (a->data > data)
			return (0);
		a = a->next;
	}
	return (1);
}