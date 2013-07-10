#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define NCHARS 1073741824l

int main(int argc, char** argv)
{
    char   a[NCHARS];
    size_t i;
    
    printf("Got %ld chars on the stack\n", NCHARS);

    for (i = 0; i < NCHARS; ++i) {
        a[i] = 'a';
    }
    
    return 0;
}

