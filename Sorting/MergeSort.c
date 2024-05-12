#include <stdio.h>
// Big O of Merge Sort is O n log n

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {9, 5, 7, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, arr_size - 1);

    printf("Sorted array is \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*Stack Trace:
mergeSort(arr = [9, 5, 7, 2], l = 0, r = 3)
    l = 0
    r = 3
    l < r
        m = 0 + (3 - 0) / 2 = 1
        mergeSort(arr = [9, 5, 7, 2], l = 0, r = 1)
            l = 0
            r = 1
            l < r
                m = 0 + (1 - 0) / 2 = 0
                mergeSort(arr = [9, 5, 7, 2], l = 0, r = 0)
                    l = 0
                    r = 0
                    l < r
                    return
                mergeSort(arr = [9, 5, 7, 2], l = 1, r = 1)
                    l = 1
                    r = 1
                    l < r
                    return
                merge(arr = [9, 5, 7, 2], l = 0, m = 0, r = 1)
                    n1 = 1 - 0 + 1 = 2
                    n2 = 1 - 0 = 1
                    L = [9]
                    R = [5]
                    i = 0
                    j = 0
                    k = 0
                    i < n1 && j < n2
                        L[0] <= R[0]
                        arr[0] = 5
                        i++
                        k++
                    i < n1
                        arr[1] = 9
                        i++
                        k++
                    j < n2
                    return
            mergeSort(arr = [5, 9, 7, 2], l = 2, r = 3)
                l = 2
                r = 3
                l < r
                    m = 2 + (3 - 2) / 2 = 2
                    mergeSort(arr = [5, 9, 7, 2], l = 2, r = 2)
                        l = 2
                        r = 2
                        l < r
                        return
                    mergeSort(arr = [5, 9, 7,
*/

// function to merge and sort two arrays
void mergeAndSort(int list1[], int list2[], int mergedList[], int size)
{
    int i = 0, j = 0, k = 0;

    while (i < size && j < size)
    {
        if (list1[i] < list2[j])
        {
            mergedList[k] = list1[i];
            i++;
        }
        else
        {
            mergedList[k] = list2[j];
            j++;
        }
        k++;
    }

    while (i < size)
    {
        mergedList[k] = list1[i];
        i++;
        k++;
    }

    while (j < size)
    {
        mergedList[k] = list2[j];
        j++;
        k++;
    }
}