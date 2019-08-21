#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char** argv)
{
    printf("SIZES\n");
    printf("=====\n");
    printf("sizeof(char)      = %ld\n", sizeof(char));
    printf("sizeof(int)       = %ld\n", sizeof(int));
    printf("sizeof(long)      = %ld\n", sizeof(long));
    printf("sizeof(size_t)    = %ld\n", sizeof(size_t));
    printf("sizeof(float)     = %ld\n", sizeof(float));
    printf("sizeof(double)    = %ld\n", sizeof(double));

    printf("RAND_MAX          = %d\n", RAND_MAX);

    return 0;
}

