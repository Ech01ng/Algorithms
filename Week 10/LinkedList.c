/*
Description: Code is to generate a linked list with random numbers.
A random amount of nodes AND a random range of numbers.
The code will print the linked list, the number of nodes, and the value of the last node.
The linked list is sorted in ascending order.
The number of nodes is generated randomly.
The value of the last node is found by traversing the linked list.
The code uses a structure to represent a node in the linked list.
The code uses a function to add a node to the linked list.
The code uses a function to print the linked list.
The code uses a function to count the number of nodes in the linked list.
The code uses a function to find the last node in the linked list.
The code uses a double pointer to modify the head pointer in the addNode function.
The code uses malloc to allocate memory for the new node.
The code uses the -> operator to access the member of a structure using a pointer.
The code uses the rand function to generate random numbers.
The code uses the srand function to generate a random seed.
The code uses the time function to generate a seed based on the current time.
The code uses the % operator to generate a random number in a specific range.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structure of a node
struct llNumber 
{
    int num;
    struct llNumber *nextNode;
};

//This function prints the linked list
void printList(struct llNumber *head) 
{
    //Traverse the linked list and print the numbers
    struct llNumber *current = head;

    //While the current node is not NULL, print the number and move to the next node
    while (current != NULL) 
    {
        //Print the number
        printf("%d ", current->num);
        //Move to the next node
        current = current->nextNode;
    }
    printf("\n");
}

//This function adds a node to the linked list
//Why use a double pointer? Because we need to modify the head pointer in the function
void addNode(struct llNumber **head, int num) 
{
    //Why use malloc? Because we need to allocate memory for the new node
    struct llNumber *newNode = (struct llNumber *)malloc(sizeof(struct llNumber));
    //Initialize the new node
    newNode->num = num;
    //The new node is the last node, so the next node is NULL
    newNode->nextNode = NULL;

    //If the linked list is empty, add the node as the head
    if (*head == NULL) 
    {
        //Update the head pointer
        *head = newNode;
    } 
    //else, add the node in the correct position
    else
    {
        //Initialize the current and previous nodes
        struct llNumber *current = *head;
        struct llNumber *prev = NULL;

        //Find the correct position to add the node
        while (current != NULL && current->num < num) 
        {
            //Keep track of the previous node
            prev = current;
            //Move to the next node
            current = current->nextNode;
        }

        //Add the node in the correct position
        if (prev == NULL) 
        {
            //Add the node at the beginning of the linked list
            newNode->nextNode = *head;
            //Update the head pointer
            *head = newNode;
        } 
        else 
        {
            //Add the node in the middle or at the end of the linked list
            prev->nextNode = newNode;
            //If the current node is not NULL, then add the new node after the current node
            newNode->nextNode = current;
        }
    }
}

//This function counts the number of nodes in the linked list
int count(struct llNumber *head) 
{
    //Initialize the count to 0
    int count = 0;

    //Traverse the linked list and count the number of nodes
    struct llNumber *current = head;

    //While the current node is not NULL, increment the count and move to the next node
    while (current != NULL) 
    {
        //Increment the count
        count++;
        //Move to the next node
        current = current->nextNode;//What does -> mean? It is used to access the member of a structure using a pointer
    }
    //Return the count
    return count;
}

//This function finds the last node in the linked list
struct llNumber *findLastNode(struct llNumber *head) 
{
    //If the linked list is empty, return NULL
    struct llNumber *current = head;
    
    //Traverse the linked list until the last node
    while (current != NULL && current->nextNode != NULL) 
    {
        //Move to the next node
        current = current->nextNode;
    }
    //Return the last node
    return current;
}

//Main function
int main() 
{
    //Generate random seed
    srand(time(0));

    //Create a linked list with random numbers
    struct llNumber *head = NULL;
    int numNumbers = rand() % 20; //Change this number to change the amount of numbers generated (i.e: 20)

    //Add random numbers to the linked list
    for (int i = 0; i < numNumbers; i++) 
    {
        int randomNumber = rand() % 101; //Change this number to generate a different range of random numbers (i.e: 0-100)
        addNode(&head, randomNumber);
    }

    printf("Linked List: ");
    printList(head);

    printf("Number of nodes: %d\n", count(head));

    //Find the last node in the linked list
    struct llNumber *lastNode = findLastNode(head);
    if (lastNode != NULL) 
    {
        //Print the value of the last node
        printf("Last node value: %d\n", lastNode->num);
    }

    return 0;
}