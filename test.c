// function bubbleSort(arr):
//     n = length(arr)
//     for i from 0 to n-1:
//         for j from 0 to n-i-1:
//             if arr[j] > arr[j+1]:
//                 swap(arr[j], arr[j+1])
# include <stdio.h>
#include "push_swap.h"

void    swap(int *a, int *b)
{
    int *tmp;

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

void rotate(int *arr)
{
    int tmp;
    int j = 0;
    t_stack *a;

    a->arr
}

// int main(int argc, char **argv)
// {
//     int i = 0;
//     // int arr[] = {12, 18 ,2 , 1 , 56 };

//     printf("--");
//     while (i< argc - 1)
//         bubblesort(argv[i++], 5);
//     while(i < 5)
//         printf(" %d", arr[i++]);
// }

void ft_lis(t_stack	*stack_a)
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

    length = malloc(stack_a->capacity * sizeof(int));
    lis = malloc(stack_a->capacity * sizeof(int));
    i = 1;
    j = -1;
    while( ++j < stack_a->capacity)
	{
        length[j] = 1;
		lis[j] = -1;
	}
    j = 0;
	max_lis = 0;
	max_lis_index = 0;
    while(i < stack_a->capacity)
    {
        while (j < i)
        {    
            if (stack_a->arr[j] < stack_a->arr[i] && length[i] <= length[j] + 1)
            {
                length[i] = length[j] + 1;
				lis[i] = j;
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
    current_value = stack_a->arr[max_lis_index];
	while(current_index >= 0)
    {
        result[current_index] = current_value;
        current_index--;
        current_value = stack_a->arr[lis[max_lis_index]];
        max_lis_index = lis[max_lis_index];
    }
	for (int i = 0; i < max_lis; i++) {
		printf("%d | ", result[i]);
	}
}