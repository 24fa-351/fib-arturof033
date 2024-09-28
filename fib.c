#include <stdio.h>
#include <stdlib.h>

/*
./fib N METHOD

N = positive integer index
METHOD = 'i' for iterative, 'r' for recursive
TEXT = text file containing integer

Adds N and the integer stored in the given text file and
outputs the first N Fibonacci numbers using the specified method
*/

#define MAX_LEN 1024

int iter_fib(int fibIndex) {
    
    int previous = 0;
    int result = 1;

    for (int ix = 1; ix <= fibIndex - 1; ix++) {
        int temp = previous + result;
        previous = result;
        result = temp;   
    }

    return result;
}

int rec_fib(int fibIndex) {
    
    if(fibIndex < 2) {
        return fibIndex;
    }

    return rec_fib(fibIndex - 1) + rec_fib(fibIndex - 2);
}
 

int main(int argc, char * argv[]) {

    char num[MAX_LEN];

    FILE *fptr;
    fptr =  fopen(argv[3], "r");
    fgets (num, MAX_LEN, fptr);

    int fibIndex = atoi(num) + atoi(argv[1]) - 1;

    if (*argv[2] == 'i') {
        printf("%d", iter_fib(fibIndex));
    }

    if (*argv[2] == 'r') {
        printf("%d", rec_fib(fibIndex));
    }

   return 0;
}
