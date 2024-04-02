/*
Name: Erik Hansen
 
Date: 06/02/23
 
Description: Power, Factorial and Fibonacci series 
*/
 
#include <stdio.h>
int power(int n1, int n2);
int fibonacci(int n1);
int factorial(int n1);
int sum(int n1);

int main()
{
    int result1, result2, result3, result4;

    result1 = power(2,6);
    printf("The power is: %d\n", result1);

    result2 = fibonacci(40);
    printf("The fibonacci is: %d\n", result2);

    result3 = factorial(5);
    printf("The factorial is: %d\n", result3);
   
    result4 = sum(51);
    printf("The sum is: %d\n", result4);

    return 0;
}

int power(int num, int powers)
{
    int A = num, B = powers;

    if (B==0)
    {
        return 1;
    }
    else
    {
        return (A*power(A, B - 1));
    }
}

int factorial(int A)
{
    if (A==0 || A==1)
    {
        return A;
    }
    else
    {
        return (A*factorial(A - 1));
    }
}

int fibonacci(int A)
{
    if (A==0 || A==1)
    {
        return A;
    }
    else
    {
        return fibonacci(A-1) + fibonacci(A-2);
    }
}

int sum(int A)
{
    if (A==0)
    {
        return 0;
    }
    else
    {
        return ((A %10) + sum(A / 10));
    }
}
