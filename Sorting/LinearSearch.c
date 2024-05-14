#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
   for (int i = 0; i < n; i++)
   {
      if (arr[i] == key)
      {
         return i; // Return the index if key is found
      }
   }
   return -1; // Return -1 if key is not found
}

int main()
{
   int arr[] = {5, 2, 9, 1, 7};
   int n = sizeof(arr) / sizeof(arr[0]);
   int key = 9;

   int result = linearSearch(arr, n, key);

   if (result == -1)
   {
      printf("Element not found\n");
   }
   else
   {
      printf("Element found at index %d\n", result);
   }

   return 0;
}