
# include <stdio.h>
#include "push_swap.h"

// void    swap(int *a, int *b)
// {
//     int *tmp;

//     tmp = *a;
//     *a = *b;
//     *b = tmp;
//     printf("sa\n");
// }
// void bubblesort(int *arr, int n)
// {
//     int i = 0;
//     int j ;
//     while(i < n-1)
//     {
//       j = 0;
//         while(j < n - i - 1)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(&arr[j], &arr[j+1]);
//             }
//             j++;
//         }
//         i++;
//     }
// }

// void rotate(int *arr)
// {
//     int tmp;
//     int j = 0;
//     t_stack *a;

//     a->arr
// }

// // int main(int argc, char **argv)
// // {
// //     int i = 0;
// //     // int arr[] = {12, 18 ,2 , 1 , 56 };

// //     printf("--");
// //     while (i< argc - 1)
// //         bubblesort(argv[i++], 5);
// //     while(i < 5)
// //         printf(" %d", arr[i++]);
// // }

// void ft_lis(t_stack	*stack_a)
// {
// 	int *length;
//     int *lis;
//     int    i;
//     int    j;
// 	int max_lis;
// 	int max_lis_index;
// 	int *result ;
// 	int current_index;
// 	int current_value;

//     length = malloc(stack_a->capacity * sizeof(int));
//     lis = malloc(stack_a->capacity * sizeof(int));
//     i = 1;
//     j = -1;
//     while( ++j < stack_a->capacity)
// 	{
//         length[j] = 1;
// 		lis[j] = -1;
// 	}
//     j = 0;
// 	max_lis = 0;
// 	max_lis_index = 0;
//     while(i < stack_a->capacity)
//     {
//         while (j < i)
//         {    
//             if (stack_a->arr[j] < stack_a->arr[i] && length[i] <= length[j] + 1)
//             {
//                 length[i] = length[j] + 1;
// 				lis[i] = j;
//             }
//             j++;
//         }
// 		if (length[i] > max_lis)
//         {
//             max_lis = length[i];
//             max_lis_index = i;
//         }
//         i++;
//         j = 0;
//     }
// 	result = malloc(max_lis * sizeof(int));
//     current_index = max_lis - 1;
//     current_value = stack_a->arr[max_lis_index];
// 	while(current_index >= 0)
//     {
//         result[current_index] = current_value;
//         current_index--;
//         current_value = stack_a->arr[lis[max_lis_index]];
//         max_lis_index = lis[max_lis_index];
//     }
// 	for (int i = 0; i < max_lis; i++) {
// 		printf("%d | ", result[i]);
// 	}
// }
////////////////////
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void appendNode(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

// Function to reverse rotate a linked list
void reverseRotateList(struct Node** headRef)
{
    if (*headRef == NULL || (*headRef)->next == NULL) {
        return;  // Empty or single-node list, no need to rotate
    }

    // Find the second-to-last node in the list
    struct Node* secondLastNode = *headRef;
    while (secondLastNode->next->next != NULL) 
    {
        secondLastNode = secondLastNode->next;
    }

    // Move the last node to the front of the list
    struct Node* lastNode = secondLastNode->next;
    secondLastNode->next = NULL;
    lastNode->next = *headRef;
    *headRef = lastNode;
}

// Function to print the contents of the list
void printList(struct Node* head) {
    struct Node* currNode = head;

    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }

    printf("\n");
}

// Main function to test the linked list functions
int main() {
    // Initialize a list with some nodes
    struct Node* head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void appendNode(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

// Function to reverse a linked list
void reverseList(struct Node** headRef) {
    struct Node* prevNode = NULL;
    struct Node* currNode = *headRef;
    struct Node* nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    *headRef = prevNode;
}

// Function to reverse rotate a linked list
void reverseRotateList(struct Node** headRef)
{
    if (*headRef == NULL || (*headRef)->next == NULL)
    {
        return;  // Empty or single-node list, no need to rotate
    }

    // Find the second-to-last node in the list
    struct Node* secondLastNode = *headRef;
    while (secondLastNode->next->next != NULL)
    {
        secondLastNode = secondLastNode->next;
    }

    // Reverse the list from the first node to the second-to-last node
    reverseList(headRef);

    // Reverse the list from the second-to-last node to the last node
    reverseList(&(secondLastNode->next));

    // Reverse the entire list to complete the rotation
    reverseList(headRef);
}

// Function to print the contents of the list
void printList(struct Node* head) {
    struct Node* currNode = head;

    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }

    printf("\n");
}

// Main function to test the linked list functions
int main() {
    // Initialize a list with some nodes
    struct Node* head = NULL;
    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    // Print the contents of the list before rotation
    printf("List contents before rotation: ");
    printList(head);

    // Reverse rotate the list
    reverseRotateList(&head);

    // Print the contents of the list after rotation
    printf("List contents after rotation: ");
    printList(head);

    return 0;
}


void reverse_rotate(t_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL) {
        return;  // Empty or single-node list, no need to rotate
    }

    t_list *ptr1 = *stack;
    t_list *ptr2 = NULL;
    while (ptr1->next != NULL) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }

    ptr1->next = *stack;
    *stack = ptr1;
    ptr2->next = NULL;
}
