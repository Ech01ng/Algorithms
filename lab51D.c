/*
Name: Erik Hansen
 
Date: 20/02/23
 
Description: two 1d arrays compare iterations and calculate 50th term in fibonacci series
*/
 
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int fibonacci(int);

//Change these values to change the amount of numbers generated
#define M 10
#define N 10

int main()
{
    int random_num[M];
    int random_num2[N];

    int num = 0;
    int num2;
    int i;
    int j;
    time_t start, end;
    int count = 0;
    int term;

    start = clock();


    for (i = 0; i < M; i++)
    {
        num = rand(); //(rand() % 10) + 1; this for testing to print a lower amount of values
        random_num[i] = num;
    }
    for (i = 0; i < M; i++)
    {
        num2 = rand(); //(rand() % 10) + 1; this for testing to print a lower amount of values
        random_num2[i] = num2;
    }

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (random_num[i] == random_num2[j])
            {
                count++;
            }
            
        }
        printf("\n%d has appeared %d times\n",random_num[i],count);
        count = 0;
    }

    term = fibonacci(num);

    end = clock();
    printf("The program took %1.7lfs time\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}

int fibonacci(int n)
{
    static int term = 0;
    term++;

    if (term == 50)
    {
        printf("\nThe 50th term is %d",n);
    }
    else
    {
        return  fibonacci(n-1) + fibonacci(n-2);
    }
}