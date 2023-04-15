/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:44:29 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/15 16:09:56 by mhirch           ###   ########.fr       */
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
// void	swap(int *a, int *b)
// {
// 	int tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// 	printf("sa\n");
// }
int push_a(t_list **a, t_list **b)
{
	t_list *temp;
	
    if (*b == NULL)
        return (0);
    temp = *b;
    *b = temp->next;
    temp->next = *a;
    *a = temp;
	return (1);
}
int push_b(t_list **a, t_list **b)
{
	t_list *temp;
	
    if (*a == NULL)
        return (0);
    temp = *a;
    *a = temp->next;
    temp->next = *b;
    *b = temp;
	return (1);
}


int rotate(t_list **stack)
{
	t_list *ptr;
	t_list *last;
	
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

int reverse_rotate(t_list **stack)
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

void	  make_operation(char *x, t_list **a, t_list **b)
{
	int i;

	if (ft_strcmp(x, "ra") == 0)
		i = rotate(a);
	else if (ft_strcmp(x, "rb") == 0)
		i = rotate(b);
	else if (ft_strcmp(x, "rr") == 0)
	{
		i = rotate(a);
		i = rotate(b);
	}
	else if (ft_strcmp(x, "pb") == 0)
		i = push_b(a, b);
	else if (ft_strcmp(x, "pa") == 0)
		i = push_a(a, b);
	else if (ft_strcmp(x, "rra") == 0)
		i = reverse_rotate(a);
	else if (ft_strcmp(x, "rrb") == 0)
		i = reverse_rotate(b);
	else if (ft_strcmp(x, "rrr") == 0)
	{
		i = reverse_rotate(a);
		i = reverse_rotate(b);
	}
	else if (ft_strcmp(x, "sa") == 0)
		i = swap(a);
	if (i == 1)
		printf("%s\n", x);
}

int	 swap(t_list **a)
{
	int temp1;
	int temp2;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	temp1 = (*a)->data;
	temp2 = (*a)->next->data;
	(*a)->next->data = temp1;
	(*a)->data = temp2;
	return (1);
}