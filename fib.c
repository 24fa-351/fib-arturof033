#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

int iterativeFibonacci(int n)
{
    int value1 = 0;
    int value2 = 1;
    int result = 0;

    for (int i = 1; i <= n; i++)
    {
        result = value1 + value2;
        value2 = value1;
        value1 = result; 
    }

    return result;
}

int recursiveFibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main(int argc, char * argv[]) {

    char num[MAX_LEN];

    FILE *fptr;
    fptr =  fopen(argv[3], "r");
    fgets (num, MAX_LEN, fptr);

    int N = atoi(num) + atoi(argv[1]) - 1;

    if (*argv[2] == 'i')
    {
        printf("%d", iterativeFibonacci(N));
    }

    if (*argv[2] == 'r')
    {
        printf("%d", recursiveFibonacci(N));
    }

   return 0;
}
