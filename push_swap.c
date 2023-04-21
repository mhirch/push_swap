/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:32:11 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/20 16:00:02 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_info	*info;
	t_list	*stack_a;

	stack_a = NULL;
	info = NULL;
	if (argc <= 1)
		return (0);
	store_and_check(&info, &stack_a, argc, argv);
	main_sort(&info, &stack_a);
	free_list(stack_a);
	free(info->arr);
	free(info);
}
