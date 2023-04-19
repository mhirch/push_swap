/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_room2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:54:49 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/19 11:46:22 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	push_a(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b == NULL)
		return (0);
	temp = *b;
	*b = temp->next;
	temp->next = *a;
	*a = temp;
	return (1);
}

int	push_b(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a == NULL)
		return (0);
	temp = *a;
	*a = temp->next;
	temp->next = *b;
	*b = temp;
	return (1);
}

int	rotate(t_list **stack)
{
	t_list	*ptr;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	ptr = *stack;
	*stack = ptr->next;
	ptr->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = ptr;
	return (1);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = *stack;
	ptr2 = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	ptr1->next = *stack;
	*stack = ptr1;
	ptr2->next = NULL;
	return (1);
}

int	swap(t_list **a)
{
	int	temp1;
	int	temp2;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	temp1 = (*a)->data;
	temp2 = (*a)->next->data;
	(*a)->next->data = temp1;
	(*a)->data = temp2;
	return (1);
}
