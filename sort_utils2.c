/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:00:29 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/16 17:19:21 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	int *moves;
	int position;
	int i,j;

	i = 0;
	j = 0;
	moves = malloc(sizeof(int) * 2);
	position = find_position(b, data);
	moves[0] = moves_stack_a(a, data);
	moves[1] = moves_stack_b(b, position);
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

int	best_one(int **moves, int i)
{
	int	j;
	int	*index;
	int	one;
	int	check;

	j = 0;
	index = malloc(sizeof(int) * i);
	while (j < i)
	{
		index[j] = calculate(moves[j][0], moves[j][1]);
		j++;
	}
	j = 0;
	check = index[j];
	one = j;
	j++;
	while (j < i)
	{
		if (check > index[j])
		{
			check = index[j];
			one = j;
		}
		j++;
	}
	return (one);
}