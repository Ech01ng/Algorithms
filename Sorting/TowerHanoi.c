#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
   if (n == 1)
   {
      printf("Move disk 1 from %c to %c\n", source, destination);
      return;
   }
   towerOfHanoi(n - 1, source, destination, auxiliary);
   printf("Move disk %d from %c to %c\n", n, source, destination);
   towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
   int n;
   printf("Enter the number of disks: ");
   scanf("%d", &n);
   towerOfHanoi(n, 'A', 'B', 'C');
   return 0;
}

/*Stack Trace:
towerOfHanoi(n = 3, source = 'A', auxiliary = 'B', destination = 'C')
    n = 3
        n != 1
        towerOfHanoi(n = 2, source = 'A', auxiliary = 'C', destination = 'B')
            n = 2
                n != 1
                towerOfHanoi(n = 1, source = 'A', auxiliary = 'B', destination = 'C')
                    n = 1
                    n == 1
                    Move disk 1 from A to C
                Move disk 2 from A to B
                towerOfHanoi(n = 1, source = 'C', auxiliary = 'A', destination = 'B')
                    n = 1
                    n == 1
                    Move disk 1 from C to B
        Move disk 3 from A to C
        towerOfHanoi(n = 2, source = 'B', auxiliary = 'A', destination = 'C')
            n = 2
                n != 1
                towerOfHanoi(n = 1, source = 'B', auxiliary = 'C', destination = 'A')
                    n = 1
                    n == 1
                    Move disk 1 from B to A
                Move disk 2 from B to C
                towerOfHanoi(n = 1, source = 'A', auxiliary = 'B', destination = 'C')
                    n = 1
                    n == 1
                    Move disk 1 from A to C
*/