/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:31:07 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/17 18:28:01 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case1(t_list **a, t_list **b, int *move_a, int *move_b)
{
	(*move_b) = (*move_b) - (*move_a);
	while ((*move_a) > 0)
	{
		make_operation("rr", a, b);
		(*move_a)--;
	}
}

void	case2(t_list **a, t_list **b, int *move_a, int *move_b)
{
	(*move_a) = (*move_a) - (*move_b);
	while ((*move_b) > 0)
	{
		make_operation("rr", a, b);
		(*move_b)--;
	}
}

void	case3(t_list **a, t_list **b, int *move_a, int *move_b)
{
	while ((*move_a) > 0)
	{
		make_operation("rr", a, b);
		(*move_a)--;
		(*move_b)--;
	}
}

void	continue_the_process(t_list **a, t_list **b, int *move_a, int *move_b)
{
	while ((*move_a) > 0)
	{
		make_operation("ra", a, b);
		(*move_a)--;
	}
	while ((*move_a) < 0)
	{
		make_operation("rra", a, b);
		(*move_a)++;
	}
	while ((*move_b) > 0)
	{
		make_operation("rb", a, b);
		(*move_b)--;
	}
	while ((*move_b) < 0)
	{
		make_operation("rrb", a, b);
		(*move_b)++;
	}
	make_operation("pa", a, b);
}

void	better_call_saul(t_list **a, t_list **b, int *moves)
{
		printf("---\n");
	if (moves[0] > 0 && moves[1] > 0)
	{
		if (small_one(moves[0], moves[1]) == 1)
			case1(a, b, &moves[0], &moves[1]);
		else if (small_one(moves[0], moves[1]) == 2)
			case2(a, b, &moves[0], &moves[1]);
		else if (small_one(moves[0], moves[1]) == 0)
			case3(a, b, &moves[0], &moves[1]);
	}
	else if (moves[0] < 0 && moves[1] < 0)
	{
		if (small_one(moves[0], moves[1]) == 1)
			case4(a, b, &moves[0], &moves[1]);
		else if (small_one(moves[0], moves[1]) == 2)
			case5(a, b, &moves[0], &moves[1]);
		else if (small_one(moves[0], moves[1]) == 0)
			case6(a, b, &moves[0], &moves[1]);
	}
	continue_the_process(a, b, &moves[0], &moves[1]);
}
