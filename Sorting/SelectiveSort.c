#include <stdio.h>
//Big O of Selection Sort is O n^2

void selectionSort(int arr[], int n);

int main() 
{
    int arr[] = {4, 2, 6, 8};

    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Sorted array: \n");

    for (int i=0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        int min_index = i;

        // j = i+1 so that it does't sort again through things sorted
        for (int j = i+1; j < n; j++) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }
        int temp = arr[i];

        arr[i] = arr[min_index];

        arr[min_index] = temp;
    }
}