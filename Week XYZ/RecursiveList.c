#include <stdio.h>
#include <time.h> 

int findNumber(int arr[], int n, int target, int index);

int main() 
{
    int list[] = {3, 6, 1, 9, 4, 7, 2, 8, 5};
    int target = 7;
    int index = findNumber(list, 9, target, 0);
    time_t start, end;

    start = clock();

    if (index != -1) 
    {
        printf("Number %d found at index %d\n", target, index);
    } 
    else 
    {
        printf("Number %d not found in the list\n", target);
    }

    end = clock();
    printf("The program took %1.7lfs time",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}

int findNumber(int arr[], int n, int target, int index) 
{
    if (index >= n) 
    {
        return -1; // number not found
    } 
    else if (arr[index] == target) 
    {
        return index; // number found at index
    } 
    else 
    {
        return findNumber(arr, n, target, index + 1); // recursively search the rest of the list
    }
}