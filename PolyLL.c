#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff;    // Coefficient
    int exp;      // Exponent
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in sorted order (by exponent)
void insertNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            int coeffSum = poly1->coeff + poly2->coeff;
            if (coeffSum != 0) {
                insertNode(&result, coeffSum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            insertNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print the polynomial
void printPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to read a polynomial from user input
void readPolynomial(struct Node** poly) {
    int n, coeff, exp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent (e.g., 3 2 for 3x^2): ");
        scanf("%d %d", &coeff, &exp);
        insertNode(poly, coeff, exp);
    }
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    printf("Enter the first polynomial\n");
    readPolynomial(&poly1);
    
    printf("Enter the second polynomial\n");
    readPolynomial(&poly2);

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Result of Addition: ");
    printPolynomial(result);

    // Free allocated memory (optional)
    // Code to free memory should be added here for production use

    return 0;
}

