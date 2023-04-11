#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
// t_list {
//     int data;
//     t_list* next;
// };

// // Function to create a new node
// t_list* createNode(int data) {
//     t_list* newNode = (t_list*)malloc(sizeof(t_list));
//     if (newNode == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to push a node to the front of the linked list
// void push(t_list** head, int data) {
//     t_list* newNode = createNode(data);
//     newNode->next = *head;
//     *head = newNode;
// }

// Function to calculate the number of moves to put an element on the top of stack B
int movesToTop(t_list* top, int data) {
    int moves = 0;
    while (top != NULL && top->data != data) {
        top = top->next;
        moves++;
    }
    return moves;
}

// Function to calculate the number of moves to put an element in its correct position in stack A
int movesToCorrectPosition(t_list* top, int data) {
    int moves = 0;
    while (top != NULL && top->data < data) {
        top = top->next;
        moves++;
    }
    return moves;
}

// Function to determine the best element in stack B to push to its correct position in stack A
int determineBestElement(t_list* stackA, t_list* stackB) {
    int bestElement = stackB->data; // Initialize with the top element of stack B
    int minMoves = movesToTop(stackA, bestElement) + movesToCorrectPosition(stackA, bestElement); // Initialize with moves for the top element

    t_list* top = stackB;
    t_list* bottom = stackB;
    int size = 0;
    // Get the size of stack B
    while (top != NULL) {
        size++;
        top = top->next;
    }

    top = stackB;
    bottom = stackB;
    int halfSize = size / 2;
    int movesTop = 0;
    int movesBottom = 0;

    // Iterate from top and bottom simultaneously, using reverse_rotate or rotate to calculate moves
    while (halfSize > 0) {
        movesTop += 1;
        top = top->next;
        halfSize--;

        if (halfSize > 0) {
            movesBottom += 1;
            bottom = bottom->next;
            halfSize--;
        }
    }

    // Determine the best element based on the minimum number of moves
    if (movesTop < movesBottom && movesTop < minMoves) {
        bestElement = top->data;
        minMoves = movesTop;
    } else if (movesBottom <= movesTop && movesBottom < minMoves) {
        bestElement = bottom->data;
        minMoves = movesBottom;
    }

    return bestElement;
}

int main() {
    // Example usage
    // Create stack A
    t_list* stackA = NULL;
    push(&stackA, 55);
    push(&stackA, 0);
    push(&stackA, -8);
    push(&stackA, 7);
    push(&stackA, 6);
    push(&stackA, 5);
    push(&stackA, 4);
    push(&stackaA, 3);




#include <stdio.h>

int main()
{
    int arr[3][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12} }; // Example 2D array

    // Printing the 2D array using nested loops
    printf("Printing 2D array arr[][]:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
