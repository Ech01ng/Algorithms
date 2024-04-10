#include <stdio.h>

//Binary search function
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        //Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        //If target greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;

        //If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    //Target is not present in array
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12; //change this value for one in array to find its index
    int result = binarySearch(arr, 0, n - 1, target); // arr for array, 0 for first value, n-1 for last value, target for target element
    if (result == -1)
        printf("Element not found in array");
    else
        printf("Element found at index %d", result);
    return 0;
}