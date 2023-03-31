/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:44:05 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/31 15:31:27 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


// void push_back(t_stack *s, int b) {
// 	if (s->size < s->capacity) {	
// 		s->arr[s->size] = b;
// 		s->size++;
// 	}
// }

// void pop_back(t_stack *s) {
// 	if (s->size > 0)
//  		s->size--;
// }

t_info *create_info(int a)
{
	t_info *s = malloc(sizeof(t_info));
	s->capacity = a;
	s->size = 0;
	s->arr = malloc(sizeof(int) * a);
	// s->node = NULL;
	return s;
}

void ft_lis(t_info	*a)
{
	int *length;
    int *lis;
    int    i;
    int    j;
	int max_lis;
	int max_lis_index;
	int *result ;
	int current_index;
	int current_value;

    length = malloc(a->capacity * sizeof(int));
    lis = malloc(a->capacity * sizeof(int));
    i = 1;
    j = -1;
    while( ++j < a->capacity)
	{
        length[j] = 1;
		lis[j] = -1;
	}
    j = 0;
	max_lis = 0;
	max_lis_index = 0;
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
		if (length[i] > max_lis)
        {
            max_lis = length[i];
            max_lis_index = i;
        }
        i++;
        j = 0;
    }
	result = malloc(max_lis * sizeof(int));
    current_index = max_lis - 1;
    current_value = a->arr[max_lis_index];
	while(current_index >= 0)
    {
        result[current_index] = current_value;
        current_index--;
        current_value = a->arr[lis[max_lis_index]];
        max_lis_index = lis[max_lis_index];
    }
}

int	main(int argc, char **argv)
{
	t_node	*stack_a ;
    t_info *info;
	int i = -1;
	
	if (argc  == 1)
		return 0;
	stack_a = store_and_check(argc, argv);
	// while(++i < info->capacity)
	// {
	// 	printf("%d ", info->arr[i]);
	// }
	ft_lis(info);
	printList(stack_a);
	// printf("%d\n", a->a->arr[0]);
    return 0;
}
