/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:27:04 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/19 12:04:10 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	length(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sorted_or_not(t_list *stack)
{
	int	data;

	data = stack->data;
	while (stack)
	{
		if (data > stack->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		data = stack->data;
		stack = stack->next;
	}
	write(1, "OK\n", 3);
	return ;
}
