/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_room1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:31:46 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/19 17:35:51 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	double_operattion(char *x, t_list **a, t_list **b)
{
	if (ft_strcmp(x, "rrr\n") == 0)
	{
		if (*a && (*a)->next && *b && (*b)->next)
		{
			reverse_rotate(a);
			reverse_rotate(b);
		}
		else if (*b == NULL || (*b)->next == NULL)
			reverse_rotate(a);
		else if (*a == NULL || (*a)->next == NULL)
			reverse_rotate(b);
	}
	else if (ft_strcmp(x, "rr\n") == 0)
	{
		if (*a && (*a)->next && *b && (*b)->next)
		{
			rotate(a);
			rotate(b);
		}
		else if (*b == NULL || (*b)->next == NULL)
			rotate(a);
		else if (*a == NULL || (*a)->next == NULL)
			rotate(b);
	}
	else if (ft_strcmp(x, "ss\n") == 0)
	{
		swap(a);
		swap(b);
	}
}

void	operation_on_a(char *x, t_list **a, t_list **b)
{
	if (ft_strcmp(x, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(x, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(x, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(x, "pa\n") == 0)
		push_a(a, b);
}

void	operation_on_b(char *x, t_list **a, t_list **b)
{
	if (ft_strcmp(x, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(x, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(x, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(x, "pb\n") == 0)
		push_b(a, b);
}

int	make_operation(char *x, t_list **a, t_list **b)
{
	while (x)
	{
		if (x == NULL)
			break ;
		if (!ft_strcmp(x, "ra\n") || !ft_strcmp(x, "rra\n")
			|| !ft_strcmp(x, "sa\n") || !ft_strcmp(x, "pa\n"))
			operation_on_a(x, a, b);
		else if (!ft_strcmp(x, "rb\n") || !ft_strcmp(x, "rrb\n")
			|| !ft_strcmp(x, "sb\n") || !ft_strcmp(x, "pb\n"))
			operation_on_b(x, a, b);
		else if (ft_strcmp(x, "rr\n") == 0 || !ft_strcmp(x, "rrr\n")
			|| !ft_strcmp(x, "ss\n"))
			double_operattion(x, a, b);
		else
		{
			write(2, "Error\n", 6);
			free(x);
			return (1);
		}
		free(x);
		x = get_next_line(0);
	}
	return (0);
}
