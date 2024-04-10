#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int mergedList[2 * MAX_SIZE];
int* mergeAndSort(int list1[], int list2[], int mergedList[], int size);
int* insertionSort(int arr[], int n);

int main() {
    int list1[MAX_SIZE];
    int list2[MAX_SIZE];
    int i;

    //Set the seed for random number generation
    srand(time(NULL));

    //Generate random numbers for list1
    for (i = 0; i < MAX_SIZE; i++) {
        list1[i] = rand() % 100; //Generate a random number between 0 and 99
    }

    //Generate random numbers for list2
    for (i = 0; i < MAX_SIZE; i++) {
        list2[i] = rand() % 100; //Generate a random number between 0 and 99
    }

    //Print the generated lists
    printf("List 1:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", list1[i]);
    }
    printf("\n");

    printf("List 2:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", list2[i]);
    }
    printf("\n");

    //Sort the lists using insertion sort
    insertionSort(list1, i);
    insertionSort(list2, i);

    //Merge and sort the two lists
    mergeAndSort(list1, list2, mergedList, MAX_SIZE);

    return 0;
}

//insertion sort function to sort list1 and list2
int* insertionSort(int array[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    return array;
}

//merge the two previous arrays into one 200 element array and sort it
int* mergeAndSort(int list1[], int list2[], int mergedList[], int size) {
    int i = 0, j = 0, k = 0;

    while (i < size && j < size) {
        if (list1[i] < list2[j]) {
            mergedList[k] = list1[i];
            i++;
        } else {
            mergedList[k] = list2[j];
            j++;
        }
        k++;
    }

    while (i < size) {
        mergedList[k] = list1[i];
        i++;
        k++;
    }

    while (j < size) {
        mergedList[k] = list2[j];
        j++;
        k++;
    }

    printf("Merged and sorted list:\n");
    for (i = 0; i < 2 * size; i++) {
        printf("%d ", mergedList[i]);
    }
    printf("\n");

    int* mergeAndSort = mergedList;

    return mergeAndSort;
}