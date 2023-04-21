/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 08:49:45 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/21 14:32:32 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*instruction;

	stack_a = NULL;
	if (argc <= 1)
		return (0);
	store_and_check(&stack_a, argc, argv);
	instruction = get_next_line(0);
	if (instruction)
	{
		if (make_operation(instruction, &stack_a, &stack_b) == 0)
			sorted_or_not(stack_a);
	}
	free_list(stack_a);
}
