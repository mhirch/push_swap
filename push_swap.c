/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:44:05 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/29 18:19:29 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void push_back(t_stack *s, int b) {
	if (s->size < s->capacity) {	
		s->arr[s->size] = b;
		s->size++;
	}
}

void pop_back(t_stack *s) {
	if (s->size > 0)
 		s->size--;
}

t_stack *create_stack(int a) {
	t_stack *s = malloc(sizeof(t_stack));
	s->capacity = a;
	s->size = 0;
	s->arr = malloc(sizeof(int) * a);
	// s->node = NULL;
	return s;
}

void ft_lis(t_stack	*a)
{
	int *length;
    // int *lis;
    int    i;
    int    j;

    length = malloc(a->capacity * sizeof(int));
    // lis = malloc(10 * sizeof(int));
    i = 1;
    j = -1;
    while( ++j < a->capacity)
        length[j] = 1;
    j = 0;
    while(i < a->capacity)
    {
        while (j < i)
        {    
            if (a->arr[j] < a->arr[i] && length[i] <= length[j] + 1)
            {
                length[i] = length[j] + 1;
            }
            j++;
        }
        i++;
        j = 0;
    }
}

int	main(int argc, char **argv)
{
	t_node *head;
	t_stack	*a;
	int i = -1;
	
	if (argc  == 1)
		return 0;
	a = store_and_check(argc, argv);
	while(++i < a->capacity)
	{
		printf("%d ", a->a->arr[i]);
	}
	ft_lis(a);
	// printList(head);
	// printf("%d\n", a->a->arr[0]);
    return 0;
}
