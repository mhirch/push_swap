/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:27 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/16 18:17:09 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sort(t_info **info, t_list **a)
{
	t_list *b;

	b = NULL;
	if (is_sorted(*a) == 1)
		return ;
	else if (length(*a) <= 5)
		simple_sort(a, &b);
	else
		sort(info, a, &b);
}

void	sort(t_info **info, t_list **a, t_list **b)
{
	t_lis_info *lis;
	int small_num;
	int position;
	
	lis = initialize_lis((*info)->capacity);
	get_index(lis, *info);
	get_lis(lis, *info);
	out_of_lis_in_b(a, b, lis, (*info)->capacity);
	free(lis);
	free(*info);
	magic(b, a);
}

int is_sorted(t_list *a)
{
	int i;

	i = length(a) - 1;
	while (i)
	{
		if (a->data < a->next->data)
			i--;
		else
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_list **a, t_list **b)
{
	int	z;
	int	y;
	int	x;
	
	z = (*a)->data;
	y = (*a)->next->data;
	x = (*a)->next->next->data;
	if (z > y && y > x && x < z)
	{
		make_operation("sa", a, b);
		make_operation("rra", a, b);
	}
	else if (z > y && y < x && x > z)
		make_operation("sa", a, b);
	else if (z < y && y > x && x < z)
		make_operation("ra", a, b);
	else if (z < y && y > x && x > z)
		make_operation("sa", a, b);
}
void	simple_sort(t_list **a, t_list **b)
{
	t_list *temp_b;
	int **moves;
	int index;
	int i;
	int	j;
	
	while (length(*a) > 3)
		make_operation("pb", a, b);
	if (length(*a) <= 3)
		sort_three(a, b);
	moves = malloc(sizeof(int *) * 2);
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
	while (is_sorted(*a) == 0)
		make_operation("ra", a, b);
}