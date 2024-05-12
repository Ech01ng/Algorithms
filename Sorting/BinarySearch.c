#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Key not found
}

// Function to sort the array using binary search
void sortArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
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

int main()
{
    int arr[] = {3, 5, 6, 1, 2, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Purpose of the above line of code?
    // The above line of code calculates the size of the array by dividing the total size of the array by the size of the first element of the array.

    // Sort the array
    sortArray(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform binary search
    int key = 6; // Change the key value to test different cases
    int index = binarySearch(arr, 0, size - 1, key);

    if (index != -1)
        printf("Element %d found at index %d\n", key, index);
    else
        printf("Element %d not found\n", key);

    return 0;
}

/*In pseudo code, how does the binary search algorithm work?
1. Set low to 0 and high to n-1, where n is the size of the array.
2. Repeat the following steps until low is less than or equal to high:
    a. Calculate mid as (low + high) / 2.
    b. If the key is equal to the element at index mid, return mid.
    c. If the key is less than the element at index mid, set high to mid - 1.
    d. If the key is greater than the element at index mid, set low to mid + 1.
3. If the key is not found, return -1.
*/

/* Does the binary search algorithm have a stack trace?
No, the binary search algorithm does not have a stack trace
as it is an iterative algorithm that does not involve function calls or recursion.
The algorithm directly manipulates the low and high indices to search for the key in the array.
*/