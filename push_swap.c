/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:32:11 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/07 18:03:27 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int is_sorted(t_info *a)
{
	int i;

	i = 0;
	while (i < a->capacity - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			i++;
		else
		{
			return 0;
		}
	}
	return 1;
}

void get_index(t_lis_info *lis, t_info *a)
{
	int	i;
	int	j;

	i = 1;
	while (i < a->capacity)
	{
		j = 0;
		while (j < i)
		{	
			if (a->arr[j] < a->arr[i] && lis->length[i] <= lis->length[j] + 1)
			{
				lis->length[i] = lis->length[j] + 1;
				lis->index_of_lis[i] = j;
			}
			j++;
		}
		if (lis->length[i] > lis->length_lis)
		{
			lis->length_lis = lis->length[i];
			lis->max_lis_index = i;
		}
		i++;
	}
	i = 0;
}

void get_lis(t_lis_info *lis, t_info *a)
{
	int current_index;
	int current_value;
	
	lis->lis = malloc(lis->length_lis * sizeof(int));
	current_index = lis->length_lis - 1;
	current_value = a->arr[lis->max_lis_index];
	while (current_index >= 0)
	{
		lis->lis[current_index] = current_value;
		current_index--;
		current_value = a->arr[lis->index_of_lis[lis->max_lis_index]];
		lis->max_lis_index = lis->index_of_lis[lis->max_lis_index];
	}
}

t_lis_info *initialize_lis(int a)
{
	int j;
	t_lis_info *lis;
	
	lis = malloc(sizeof(t_lis_info));
	lis->length_lis = 0;
	lis->max_lis_index = 0;
	lis->length = malloc(a * sizeof(int));
	lis->index_of_lis = malloc(a * sizeof(int));
	j = 0;
	while( j < a)
	{
		lis->length[j] = 1;
		lis->index_of_lis[j++] = -1;
	}
	return(lis);
}

void	sort(t_info **info, t_list **a)
{
	t_list *b;
	t_lis_info *lis;
	lis = initialize_lis((*info)->capacity);
	get_index(lis, *info);
	get_lis(lis, *info);
	for (int i = 0; i < lis->length_lis; i++) {
		printf("%d | ", lis->lis[i]);
	}
	printf("\n%d", lis->length_lis);
	while ((*info)->capacity-- > 0)
	{
		if (is_lis_in_stack(*a, lis) == 1)
			rotate
		else
			push(b);
			
	}
}
int is_lis_in_stack(t_list *a, t_lis_info *lis)
{
	int	i;

	i = 0;
	while (i < lis->length_lis)
	{
		if (lis->lis[i] == a->data)
			return (1);
		i++;
	}
	return (0);
}

void	main_sort(t_info **info, t_list **a)
{
	if (is_sorted(*info) == 1)
	{
		printf("sorted");
		return ;
	}
	if ((*info)->capacity <= 5)
		bubblesort((*info)->arr, (*info)->capacity);
	else
		sort(info, a);
}
// void	main_sort(t_info **a)
// {
// 	if (is_sorted(*a) == 1)
// 	{
// 		printf("sorted");
// 		return ;
// 	}
// 	if ((*a)->capacity <= 5)
// 		bubblesort((*a)->arr, (*a)->capacity);
// 	else
// 		sort(&*a);
// }


void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	printf("sa\n");
}
void bubblesort(int *arr, int n)
{
	int i = 0;
	int j ;
	while(i < n-1)
	{
	  j = 0;
		while(j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j+1]);
			}
			j++;
		}
		i++;
	}
}
int main(int argc, char **argv)
{
	t_info	*info;
	t_list *stack_a;
	
	int i = 0;
	stack_a = NULL;
	info = NULL;
	if (argc <= 2)
		return (0);
	store_and_check(&info, &stack_a, argc, argv);
	printf("\n");
	// while(i < stack_a->capacity)
	// 	printf(" %d", stack_a->arr[i++]);
	main_sort(&info, &stack_a);
}