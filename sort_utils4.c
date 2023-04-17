/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:26:51 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/17 18:12:45 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_one(int a, int b)
{
	int	r;

	if (ft_abs(a) < ft_abs(b))
		r = 1;
	else if (ft_abs(a) > ft_abs(b))
		r = 2;
	else
		r = 0;
	return (r);
}

int	smallest_in_stack(t_list *a)
{
	int	small_num;

	small_num = INT_MAX;
	while (a->next)
	{
		if (a->data < small_num)
			small_num = a->data;
		a = a->next;
	}
	if (a->data < small_num)
			small_num = a->data;
	return (small_num);
}

int	small_in_top(t_list **a, t_list **b, int capacity, int small_num)
{
	int	position;

	position = find_position(*a, small_num);
	while (capacity-- > 0)
	{
		if (find_position(*a, small_num) != 0)
		{
			if (find_position(*a, small_num) <= (capacity / 2))
			{
				make_operation("ra", a, b);
			}
			else if (find_position(*a, small_num) > (capacity / 2))
			{
				make_operation("rra", a, b);
			}
		}
		else
			break ;
	}
	return (position);
}

int	bigger_than_data(t_list *a, int data, int i)
{
	int	*bigger;
	int	j;
	int	one;

	j = 0;
	bigger = malloc(sizeof(int) * i);
	while (a)
	{
		if (a->data > data)
			bigger[j++] = a->data;
		a = a->next;
	}
	j = 0;
	one = bigger[j++];
	while (j < i)
	{
		if (one > bigger[j])
			one = bigger[j];
		j++;
	}
	free(bigger);
	return (one);
}

int	biggest_one(t_list *a)
{
	int	bigg_num;

	bigg_num = INT_MIN;
	while (a->next)
	{
		if (a->data > bigg_num)
			bigg_num = a->data;
		a = a->next;
	}
	if (a->data > bigg_num)
			bigg_num = a->data;
	return (bigg_num);
}
