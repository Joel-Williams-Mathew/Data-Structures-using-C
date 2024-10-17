#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow: Stak is full\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}


// Function to pop an element from the stack
void pop(struct Node** top) {
    struct Node* temp;
     if (*top == NULL)
    {
        printf("Stack Overflow: Stack is empty");
        return;
    }// List is empty
    else{
    temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Element popped!");
   
    }
}

// Function to display the stack
void display(struct Node* top) {
     if (top == NULL)
    {
        printf("Stack Overflow: Stack is empty");
        return;
    }// List is empty
    else{
    struct Node* temp = top;
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
}
// Main function to demonstrate stack operations

int main() {
    struct Node* top = NULL;
    int choice, data, position;

    do {
        printf("\n\tMenu\n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Display \n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                pop(&top);
                break;
           
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the linked list before exiting
    while (top != NULL) {
       pop(&top);
    }

    return 0;
}
