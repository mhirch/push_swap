/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:32:11 by mhirch            #+#    #+#             */
/*   Updated: 2023/04/12 17:23:39 by mhirch           ###   ########.fr       */
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

	position = 0;
	while (stack->next)
	{
		if (stack->data == number)
			break ;
		position++;
		stack = stack->next;
	}
	return (position);
}
int	smallest_in_stack(t_list *a)
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
	return (small_num);
}
int	small_in_top(t_list **a, t_list **b, int capacity, int small_num)
{
	int position;

	position = find_position(*a, small_num);
	while (capacity-- > 0)
	{
		if (find_position(*a, small_num) != 0)
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
int	data_is_biggest(t_list *a, int data)
{
	while (a)
	{
		if (a->data > data)
			return (0);
		a = a->next;
	}
	return (1);
}
int bigger_than_data(t_list *a, int data, int i)
{
	int bigger[i];
	int j;
	int one;
	
	j = 0;
	while (a)
	{
		if (a->data > data)
			bigger[j++] = a->data;
		a = a->next;
	}
	j = 0;
	one = bigger[j++];
	while (j < i)
	{
		if (one > bigger[j])
			one = bigger[j];
		j++;
	}
	return (one);
}
int	moves_stack_a(t_list *a, int data)
{
	t_list *temp;
	int moves;
	int i;
	int to_be_replaced;
	int position;

	i = 0;
	temp = a;
	if (data_is_biggest(a, data) == 0)
	{
		while (temp)
		{
			if (temp->data > data)
				i++;
			temp = temp->next;
		}
		to_be_replaced = bigger_than_data(a, data, i);
	}
	else 
		to_be_replaced = biggest_one(a);
	position = find_position(a, to_be_replaced);
	moves = 0;
	i = length(a);
	if (position < i / 2)
		moves = position;
	if (position >= i / 2)
		moves = (i - position) * -1;
	return (moves);
}
int	biggest_one(t_list *a)
{
	int bigg_num;

	bigg_num = INT_MIN;
	while (a->next)
	{
		if (a->data > bigg_num)
			bigg_num = a->data;
		a = a->next;
	}
	if (a->data > bigg_num)
			bigg_num = a->data;
	return (bigg_num);
}
int	moves_stack_b(t_list *b, int position)
{
	int	moves;
	int j;
	
	moves = 0;
	j = length(b);
	if (position < j / 2)
		moves = position;
	if (position >= j / 2)
		moves = (j - position) * -1;
	return (moves);
}
int	*calcul_moves(t_list *a, t_list *b, int data)
{
	t_list *temp_b;
	int *moves;
	int position;
	int i,j;

	i = 0;
	j = 0;
	moves = malloc(sizeof(int) * 2);
	temp_b = b;
	position = find_position(b, data);
	moves[0] = moves_stack_a(a, data);
		printf("moves in A %d\n", moves[0]);
	moves[1] = moves_stack_b(b, position);
		printf("moves in B %d\n", moves[1]);
	
	return (moves);
}
int ft_abs(int x)
{
    if (x < 0) 
        return -x;
    else
        return x;
}
int calculate(int a, int b)
{
    int result;
	int abs_a;
	int abs_b;

	abs_a = ft_abs(a);
	abs_b = ft_abs(b);
    if (a == b)
        result = abs_a;
    else if ((a < 0 & b < 0) || (a > 0 & b > 0))
        result = (abs_a > abs_b) ? abs_a : abs_b;
	else if ((a < 0 && b >= 0))
		result = abs_a + abs_b;
	else if ((b < 0 && a >= 0))
		result = abs_a + abs_b;
	return result;
}
void	magic(t_list **b,t_list **a)
{
	t_list *temp_b;
	int **moves;
	int i;
	int index;
	int j = 0;
	
	moves = malloc(sizeof(int *) * length(*b));
	// while (*b)
	// {
		i = 0;
		temp_b = *b;
		while(temp_b)
		{
			moves[i++] = calcul_moves(*a, *b, temp_b->data);
			temp_b = temp_b->next;
		}
		index = best_one(moves, length(*b));
		
		
		
	// }
}
int	best_one(int **moves, int i)
{
	int j;
	int *index;
	int one;
	int check;

	j = 0;
	index = malloc(sizeof(int) * i);
	while( j < i)
	{
		index[j] = calculate(moves[j][0], moves[j][1]);
		j++;
	}
	j = 0;
	check = index[j];
	one = j;
	j++;
	while (j < i)
	{
		if ( check > index[j])
		{
			check = index[j];
			one = j;
		}
		j++;
	}
	return (one);
		
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