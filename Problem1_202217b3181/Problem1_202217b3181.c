#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* Function prototypes */
void create();
void insert();
void deletion();
void search();
void display();

/* Global variables */
int b[MAX], n = 0;

/* Main function */
int main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        /* Call the appropriate function based on user choice */
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nEnter the correct choice:");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');

    return 0;
}

/* Function to create the list */
void create() {
    printf("\nEnter the number of nodes (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Exceeds maximum limit. Setting to %d.\n", MAX);
        n = MAX;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

/* Function to delete an element from the list */
void deletion() {
    int pos;
    printf("\nEnter the position you want to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid location.");
    } else {
        for (int i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
        printf("\nThe elements after deletion:");
        display();
    }
}

/* Function to search an element in the list */
void search() {
    int e;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value %d is in position %d\n", e, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

/* Function to insert an element into the list */
void insert() {
    int pos, p;
    if (n == MAX) {
        printf("\nList is full. Cannot insert.");
        return;
    }

    printf("\nEnter the position you need to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("\nInvalid location.");
    } else {
        for (int i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }
        printf("\nEnter the element to insert: ");
        scanf("%d", &p);
        b[pos] = p;
        n++;
        printf("\nThe list after insertion:");
        display();
    }
}

/* Function to display the list */
void display() {
    printf("\nThe elements of the list are:");
    for (int i = 0; i < n; i++) {
        printf(" %d", b[i]);
    }
    printf("\n");
}