#include <stdio.h>

void insertionSort(int arr[], int n);

int main() {
    //int arr[] = {4, 6, 1, 2};
    int arr[] = {6, 4, 2, 1};
    //int arr[] = {1, 4, 2, 6};
    
    //By dividing the total size of the array by the size of one element
    //You get the number of elements in the array.
    int n = sizeof(arr) / sizeof(arr[0]);


    insertionSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    int OperationCounter = 0; //Initialize the OperationCounter
    int LoopCounter = 0; //Initialize the LoopCounter
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            LoopCounter++; //Increment LoopCounter each time the while loop runs
            OperationCounter++; //Increment OperationCounter each time the while loop runs
        }
        arr[j + 1] = key;
        OperationCounter++; //Increment OperationCounter each time the while loop runs
    }
    printf("Number of Operations: %d\n", OperationCounter); // Print the OperationCounter
    printf("Number of Loops: %d\n", LoopCounter); // Print the LoopCounter
}