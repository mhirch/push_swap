#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a node to the linked list
void addNode(struct Node **head, int data) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else
    {
        struct Node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) 
{
    struct Node* head = NULL;
    
    // Loop through each argument
    for (int i = 1; i < argc; i++) {
        // Convert argument to integer
        int data = atoi(argv[i]);
        
        // Add integer to linked list
        addNode(&head, data);
    }
    
    // Print the linked list
    printList(head);
    
    return 0;
}
