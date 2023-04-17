/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_room1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:56:06 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/17 16:40:22 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_operattion(char *x, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	if (ft_strcmp(x, "rrr") == 0)
	{
		i = reverse_rotate(a);
		i = reverse_rotate(b);
	}
	else if (ft_strcmp(x, "rr") == 0)
	{
		i = rotate(a);
		i = rotate(b);
	}
	return (i);
}

void	make_operation(char *x, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	if (ft_strcmp(x, "ra") == 0)
		i = rotate(a);
	else if (ft_strcmp(x, "rb") == 0)
		i = rotate(b);
	else if (ft_strcmp(x, "rr") == 0)
		i = double_operattion("rr", a, b);
	else if (ft_strcmp(x, "pb") == 0)
		i = push_b(a, b);
	else if (ft_strcmp(x, "pa") == 0)
		i = push_a(a, b);
	else if (ft_strcmp(x, "rra") == 0)
		i = reverse_rotate(a);
	else if (ft_strcmp(x, "rrb") == 0)
		i = reverse_rotate(b);
	else if (ft_strcmp(x, "rrr") == 0)
		i = double_operattion("rrr", a, b);
	else if (ft_strcmp(x, "sa") == 0)
		i = swap(a);
	if (i == 1)
		printf("%s\n", x);
}
