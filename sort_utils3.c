/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:09:56 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/17 18:17:08 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	calculate(int a, int b)
{
	int	result;
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(a);
	abs_b = ft_abs(b);
	if (a == b)
		result = abs_a;
	else if ((a < 0 & b < 0) || (a > 0 & b > 0))
	{
		if (abs_a > abs_b)
			result = abs_a;
		else
			result = abs_b;
	}
	else
		result = abs_a + abs_b;
	return (result);
}

int	moves_stack_b(t_list *b, int position)
{
	int	moves;
	int	j;

	moves = 0;
	j = length(b);
	if (position < j / 2)
		moves = position;
	if (position >= j / 2)
		moves = (j - position) * -1;
	return (moves);
}

int	place_to_be_replaced(t_list *a, int data)
{
	t_list	*temp;
	int		to_be_replaced;
	int		i;

	i = 0;
	temp = a;
	if (data_is_biggest(a, data) == 0)
	{
		while (temp)
		{
			if (temp->data > data)
				i++;
			temp = temp->next;
		}
		to_be_replaced = bigger_than_data(a, data, i);
	}
	else
		to_be_replaced = smallest_in_stack(a);
	return (to_be_replaced);
}

int	moves_stack_a(t_list *a, int data)
{
	int	moves;
	int	i;
	int	position;
	int	j;

	j = place_to_be_replaced(a, data);
	position = find_position(a, j);
	i = length(a);
	if (position < i / 2)
		moves = position;
	if (position >= i / 2)
		moves = (i - position) * -1;
	return (moves);
}
