#include <stdio.h>

void bubbleSort(int arr[], int n);

int main()
{
    int arr[] = {4, 6, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Sorted array: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }
}

/*Pseudocode:
bubbleSort(arr[], n)
    for i = 0 to n - 1
        for j = 0 to n - i - 1
            if arr[j] > arr[j + 1]
                swap arr[j] and arr[j + 1]
return arr[]

Time Complexity:
Best Case: O(n)
Worst Case: O(n^2)
Average Case: O(n^2)
*/

/*Stack Trace:
bubbleSort(arr = {4, 6, 1, 2}, n = 4)
    i = 0
        j = 0
            arr[0] = 4 > arr[1] = 6
            arr = {6, 4, 1, 2}
        j = 1
            arr[1] = 4 < arr[2] = 1
            arr = {6, 1, 4, 2}
        j = 2
            arr[2] = 4 > arr[3] = 2
            arr = {6, 1, 2, 4}
    i = 1
        j = 0
            arr[0] = 6 > arr[1] = 1
            arr = {1, 6, 2, 4}
        j = 1
            arr[1] = 6 > arr[2] = 2
            arr = {1, 2, 6, 4}
    i = 2
        j = 0
            arr[0] = 1 < arr[1] = 2
            arr = {1, 2, 6, 4}
        j = 1
            arr[1] = 2 < arr[2] = 6
            arr = {1, 2, 6, 4}
    i = 3
        j = 0
            arr[0] = 1 < arr[1] = 2
            arr = {1, 2, 6, 4}
        j = 1
            arr[1] = 2 < arr[2] = 6
            arr = {1, 2, 6, 4}
        j = 2
            arr[2] = 6 > arr[3] = 4
            arr = {1, 2, 4, 6}
*/