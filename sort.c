/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:27 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/14 16:56:39 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(t_info **info, t_list **a)
{
	t_list *b;
	t_lis_info *lis;
	int small_num;
	int position;
	
	b = NULL;
	small_num = smallest_in_stack(*a);
	position = small_in_top(a, &b, (*info)->capacity, small_num);
	// update_arr(info, *a);
	// for (int i = 0; i < (*info)->capacity; i++) {
	// 	printf("%d | ", (*info)->arr[i]);
	// }
	// printf("\n");
	lis = initialize_lis((*info)->capacity);
	get_index(lis, *info);
	get_lis(lis, *info);
	// for (int i = 0; i < lis->length_lis; i++) {
	// 	printf("%d | ", lis->lis[i]);
	// }
	// printf("\n");
	out_of_lis_in_b(a, &b, lis, (*info)->capacity);
	magic(&b, a);
	/*-------------*/
	// printList(*a);
	// printList(b);
	/*-------------*/
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
