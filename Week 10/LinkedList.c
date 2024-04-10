#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the beginning of the linked list
void insert(Node** head, int data) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;

    // Update the head pointer to point to the new node
    *head = newNode;
}

// Function to generate a random number in the given range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an empty linked list
    Node* head = NULL;

    // Generate a random number of random numbers
    int numNumbers = generateRandomNumber(1, 10);
    for (int i = 0; i < numNumbers; i++) {
        int randomNumber = generateRandomNumber(0, 100);
        insert(&head, randomNumber);
    }

    // Print the linked list
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}