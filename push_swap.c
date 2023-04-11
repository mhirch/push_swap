/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:32:11 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/11 18:10:06 by mhirch           ###   ########.fr       */
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

int	find_position(t_list *stack, int number)
{
	int position;

	position = 1;
	while (stack->next)
	{
		if (stack->data == number)
			break ;
		position++;
		stack = stack->next;
	}
	return (position);
}
int	find_smallest(t_list *a)
{
	int small_num;

	small_num = INT_MAX;
	while (a->next)
	{
		if (a->data < small_num)
			small_num = a->data;
		a = a->next;
	}
	if (a->data < small_num)
			small_num = a->data;
	return small_num;
}
int	small_in_top(t_list **a, t_list **b, int capacity, int small_num)
{
	int position;

	position = find_position(*a, small_num);
	while (capacity-- > 0)
	{
		if (find_position(*a, small_num) != 1)
		{
			if (find_position(*a, small_num) <= (capacity / 2))
			{
				make_operation("ra", a, b);
			}
			else if (find_position(*a, small_num) > (capacity / 2))
			{
				make_operation("rra", a, b);
			}
		}
		else 
			break ;
	}
	return (position);
}
void	update_arr(t_info **info, t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		(*info)->arr[i++] = a->data;
		a = a->next;
	}
}
void	out_of_lis_in_b(t_list **a, t_list **b, t_lis_info *lis, int capacity)
{
	while (capacity-- > 0)
	{
		if (is_lis_in_stack(*a, lis) == 1)
			make_operation("ra", a, b);
		if (is_lis_in_stack(*a, lis) == 0)
			make_operation("pb", a, b);
	}
}
int length(t_list *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
int moves_stack_a(t_list *a, int data)
{
	int moves;

	moves = 0;
	return (moves);
}
int	moves_stack_b(t_list *b, int data, int position)
{
	int	moves;
	t_list *temp;
	int j;
	
	moves = 0;
	temp = b;
	j = length(b) / 2;
	if (position == 1)
		moves = 0;
	printf("hh%dhh", position);
	if (position <= j && position != 1)
	{
		// while (b && temp->data != data)
		// {
		// 	b = b->next;
		// 	moves++;
		// }
		while(b)
			b = b->next;
		while(data != temp->data)
			temp = temp->next;
		while (temp->data != b->data)
		{
			temp = temp->next;
			moves++;
		}
	}
	// if (position <= length(b) / 2 && position != 0)
	// {
		
	// }
	printf("*-%d*-\n", moves);
	return (moves);
}
int	*what_is_best_moves(t_list *a, t_list *b, int position, int data)
{
	int moves[2];
	int i;
	t_list *temp_b;

	i = 0;
	temp_b = b;
	// moves[0] = moves_stack_a(a, data);
	moves[1] = moves_stack_b(b, data, position);
	moves[0] = 0;
	
	// while (temp_b)
	// {
	// 	if (position <= length(temp_b) / 2 && position != 0)
			
	// }
	// while (a)
	// {
	// 	if ()
	// }
	return (moves);
}
void	magic(t_list **b,t_list **a)
{
	t_list *temp_b;
	int position;
	int **moves;
	int i;
	
	moves = malloc(sizeof(int *) * length(*b));
	// while (*b)
	// {
		temp_b = *b;
		while(temp_b)
		{
			position = find_position(*b, temp_b->data);
			moves[i] = what_is_best_moves(*a, *b, position, temp_b->data);
			i++;
			temp_b = temp_b->next;
		}
		// for (int i = 0; i < length(*b); i++) {
        // 	for (int j = 0; j < 2; j++) {
        //     	printf("%d ", moves[i][j]);
        // }
        // printf("\n");
    // }
		// printf("****%d\n", temp_b->next->next->data);
		// int move = calculatemoves(*a, temp_b->next->next->data);
		// printf("------%d\n", move);
		
	// }
}
void	sort(t_info **info, t_list **a)
{
	t_list *b;
	t_lis_info *lis;
	int small_num;
	int position;
	
	b = NULL;
	small_num = find_smallest(*a);
	position = small_in_top(a, &b, (*info)->capacity, small_num);
	update_arr(info, *a);
	for (int i = 0; i < (*info)->capacity; i++) {
		printf("%d | ", (*info)->arr[i]);
	}
	printf("\n");
	lis = initialize_lis((*info)->capacity);
	get_index(lis, *info);
	get_lis(lis, *info);
	for (int i = 0; i < lis->length_lis; i++) {
		printf("%d | ", lis->lis[i]);
	}
	printf("\n");
	out_of_lis_in_b(a, &b, lis, (*info)->capacity);
	magic(&b, a);
	/*-------------*/
	printList(*a);
	printList(b);
	/*-------------*/
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