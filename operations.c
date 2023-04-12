/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:44:29 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/11 22:43:37 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(int a, int b, int x)
// {
//     int tmp;
	
// 	stack->arr
// }
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void push_a(t_list **a, t_list **b)
{
	t_list *temp;
	
    if (*b == NULL)
        return ;
    temp = *b;
    *b = temp->next;
    temp->next = *a;
    *a = temp;
}
void push_b(t_list **a, t_list **b)
{
	t_list *temp;
	
    if (*a == NULL)
        return ;
    temp = *a;
    *a = temp->next;
    temp->next = *b;
    *b = temp;
}


void rotate(t_list **stack)
{
	t_list *ptr;
	t_list *last;
	
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	ptr = *stack;
	*stack = ptr->next;
	ptr->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = ptr;
}
void fake_rotate(t_list *stack)
{
	t_list *ptr;
	t_list *last;
	
	if (stack == NULL || stack->next == NULL)
		return ;
	ptr = stack;
	stack = ptr->next;
	ptr->next = NULL;
	last = stack;
	while (last->next != NULL)
		last = last->next;
	last->next = ptr;
}

void reverse_rotate(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;
	
	ptr1 = *stack;
	ptr2 = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	ptr1->next = *stack;
	*stack = ptr1;
	ptr2->next = NULL;
}
void fake_reverse_rotate(t_list *stack)
{
	t_list	*ptr1;
	t_list	*ptr2;
	
	ptr1 = stack;
	ptr2 = NULL;
	if (stack == NULL || stack->next == NULL)
		return ;
	while (ptr1->next != NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	ptr1->next = stack;
	stack = ptr1;
	ptr2->next = NULL;
}

void	  make_operation(char *x, t_list **a, t_list **b)
{
	if (ft_strcmp(x, "ra") == 0)
		rotate(a);
	else if (ft_strcmp(x, "rb") == 0)
		rotate(b);
	else if (ft_strcmp(x, "rr") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(x, "pb") == 0)
		push_b(a, b);
	else if (ft_strcmp(x, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(x, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(x, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(x, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	printf("%s\n", x);
}
