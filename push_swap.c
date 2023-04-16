/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:32:11 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/16 17:55:59 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printList(t_list *head)
{
	t_list* temp;
	
	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void	f()
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	atexit(f);
	t_info	*info;
	t_list	*stack_a;
	int		i;

	i = 0;
	stack_a = NULL;
	info = NULL;
	if (argc <= 2)
		return (0);
	store_and_check(&info, &stack_a, argc, argv);
	main_sort(&info, &stack_a);
	// printList(stack_a);
	free(stack_a);
	free(info);
}
