/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:40:39 by mhirch            #+#    #+#             */
/*   Updated: 2023/03/14 17:11:01 by mhirch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// int[100];
// count = 0;

// void push()
// {
    
// }

// int main () {
//     t_stack *s = create_stack(1000);
//     int i = -1;
//     while (++i < s->capacity)
//     {
//         push_back(s,i);
//     }
//     i = -1;
//     // pop_back(s);
    
//     while (++i < s->size)
//          printf("%d\n", s->arr[i]);
// }

// int	ft_isdigit(char *m)
// {
// 	int isDigit = 1;
// 	int j=0;
	
//     if(!m[j])
//         isDigit = 0;
// 	while(m[j] && isDigit == 1)
// 	{
//   		if( m[j] >= 48 && m[j] <= 57)
//   		  isDigit = 1;
//  		else
//   		  isDigit = 0;
//   		j++;
// 	}
// 	return(isDigit);
// }
// int main()
// {
//     int i = ft_isdigit("9");
//     printf( " %d \n", i);
// }

#include <stdio.h>
#include <stdlib.h>

// Define a node struct for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a stack struct that contains a pointer to the top node of the linked list
struct Stack {
    struct Node* top;
};

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    // Create a new node for the data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    // Make the new node point to the current top node of the stack
    newNode->next = stack->top;
    // Make the top pointer of the stack point to the new node
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    // Check if the stack is empty
    if (stack->top == NULL) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    // Save the data of the top node
    int data = stack->top->data;
    // Move the top pointer to the next node
    stack->top = stack->top->next;
    // Free the memory of the previous top node
    free(stack->top);
    return data;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

int main() {
    // Initialize a new stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;

    // Loop to push elements onto the stack
    int data;
    while (1) {
        printf("Enter data to push onto the stack (or -1 to stop): ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        push(stack, data);
    }

    // Loop to pop elements from the stack and print them
    printf("\nPopping elements from
