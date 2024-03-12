#include <stdio.h>

void findMaxAndMin(int A[], int N, int* max, int* min) {
    //Initialize max and min with the first element of the array
    *max = A[0];
    *min = A[0];

    //Traverse the array and update max and min accordingly
    for (int i = 1; i < N; i++) {
        if (A[i] > *max) {
            *max = A[i];
        }
        if (A[i] < *min) {
            *min = A[i];
        }
    }
}

int main() {
    int A[] = {5, 2, 9, 1, 7}; //Example array
    int N = sizeof(A) / sizeof(A[0]); //Calculate the size of the array

    int max, min;
    findMaxAndMin(A, N, &max, &min);

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}