/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:44:29 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/08 17:44:00 by mhirch           ###   ########.fr       */
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

void push_b(t_list **a, t_list **b)
{
    int data;
    t_list *temp;
    
    if (*a == NULL)
        return ;
    if (*b == NULL)
        *b = newnode((*a)->data);
	else
	{
    	data = (*a)->data;
    	temp = newnode((*a)->data);
    	temp->next = *b;
    	*b = temp;
	}
	*a = (*a)->next;
}

void    make_operation(char *x, t_list **a, t_list **b)
{
    if (ft_strcmp(x, "ra") == 0)
        rotate(*a);
    else if (ft_strcmp(x, "pb") == 0)
        push_b(a, b);
    printf("%s\n", x);
}
// void	rotate(t_list *stack)
// {
// 	t_list *ptr;
// 	int temp;
	
// 	ptr = stack;
// 	while(ptr->next != NULL)
// 		ptr = ptr->next;
// 	temp = stack->data ;
// 	stack->data = ptr->data;
// 	while (stack->next)
// 		stack = stack->next;
// 	stack->data = temp;
// }
void	rotate(t_list *stack)
{
	t_list *ptr;
	int data;
	
	data = stack->data;
	// ptr = *stack;
	while (stack->next != NULL)
		stack = stack->next;
	stack = stack->next;
	stack->next = newnode(data);
}
