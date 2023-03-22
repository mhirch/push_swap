#include <stdio.h>
#include <stdlib.h>

// // Define a node structure for the linked list
// struct Node {
//     int data;
//     struct Node* next;
// };

// // Function to add a node to the linked list
// void addNode(struct Node **head, int data) 
// {
//     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
    
//     if (*head == NULL) 
//     {
//         *head = newNode;
//     } 
//     else
//     {
//         struct Node* temp = *head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// // Function to print the linked list
// void printList(struct Node* head) {
//     struct Node* temp = head;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// // int main(int argc, char* argv[]) 
// // {
// //     struct Node* head = NULL;
    
// //     // Loop through each argument
// //     for (int i = 1; i < argc; i++) {
// //         // Convert argument to integer
// //         int data = atoi(argv[i]);
        
// //         // Add integer to linked list
// //         addNode(&head, data);
// //     }
    
// //     // Print the linked list
// //     printList(head);
    
// //     return 0;
// // }


// /////////////////////////////////////////////////////////////////////////////////////////
// void addNode(t_node **head, int data) 
// {
//     t_node *newNode;
// 	t_node* temp;
	
// 	newNode = (t_node*)malloc(sizeof(t_node));
//     newNode->data = data;
//     newNode->next = NULL;
//     if (*head == NULL) 
//         *head = newNode;
//     else
//     {
//         temp = *head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// void printList(t_node* head)
// {
//     t_node* temp;
	
// 	temp = head;
//     while (temp != NULL)
// 	{
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }


// int main(int argc, char **argv)
// {
// 	// int args[100];
// 	int i;
//     // int num_args;
// 	// t_stack *s ;
// 	// if(argc > 1)
// 	// {
// 	// 	num_args = store_arguments(argc, argv, args);
//     // 	// printf("number of Arguments: %d\n", argc - 1);
//   	// 	if (num_args == -1)
//     // 	    return 1;
// 	// }
// 	i = 0;
// 	while(++i < argc)
// 		check_and_convert(argc, argv[i]);
// 	// printList(head);
//     return 0;
// }
///////////////////////////////////////////////

// #include <stdarg.h>
// #include <string.h>

// int total_length(int count, ...) {
//     va_list args;
//     va_start(args, count);
    
//     int total_len = 0;
//     int i = 0;
//     while( i < count ) 
//     {
//         char* arg = va_arg(args, char*);
//         total_len += strlen(arg);
//         i ++;
//     }
    
//     va_end(args);
//     return total_len;
// }
// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     int i = 1;
//     int length;

//     while(i < argc)
//     {
//         length = total_length(argc, argv[i++]);
//     }
//     printf("Total length: %d\n", length);
//     return 0;
// }
///////////////////////////////////////////
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char* total_length(int count, ...) {
    va_list args;
    va_start(args, count);
    int i = 0;
    int j = 0;
    
    // Allocate an array of strings to store the arguments
    char** arg_array = malloc(count * sizeof(char*));
    if (arg_array == NULL) {
        va_end(args);
        return NULL;
    }
    
    // Copy each argument into the array
    while ( i < count)
    {
        char* arg = va_arg(args, char*);
        arg_array[i] = malloc(strlen(arg) + 1);
        if (arg_array[i] == NULL) {
            while (j < i)
                free(arg_array[j]);
            j++;
            free(arg_array);
            va_end(args);
            return NULL;
        }
        strcpy(arg_array[i], arg);
        i++;
    }
    
    va_end(args);
    
    // Calculate the total length of all arguments
    int total_len = 0;
    for (int i = 0; i < count; i++) {
        total_len += strlen(arg_array[i]);
    }
    
    // Concatenate all arguments into a single string
    char* result = malloc(total_len + 1);
    if (result == NULL) {
        for (int i = 0; i < count; i++) {
            free(arg_array[i]);
        }
        free(arg_array);
        return NULL;
    }
    
    int pos = 0;
    for (int i = 0; i < count; i++) {
        strcpy(result + pos, arg_array[i]);
        pos += strlen(arg_array[i]);
    }
    
    // Free memory and return the result
    for (int i = 0; i < count; i++) {
        free(arg_array[i]);
    }
    free(arg_array);
    
    return result;
}

#include <stdio.h>

// int main() {
//     char* result = total_length(3, "hello", "world", "!");
//     if (result != NULL) {
//         printf("Result: %s\n", result);
//         free(result);
//     }
//     return 0;
// }
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    // Declare an array to store the command-line arguments
    char **args = (char**) malloc(argc * sizeof(char*));
    
    // Copy each command-line argument into the array
    while(i < argc)
    {
        args[i] = argv[i];
        i++;
    }
    
    // Print the contents of the array
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, args[i]);
    }
    
    // Free the memory allocated for the array
    free(args);
    
    return 0;
}
