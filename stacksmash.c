#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define GIG 1073741824l

int main(int argc, char** argv)
{
    char   a[GIG];
    size_t i;
    
    printf("Got %ld chars on the stack\n", GIG);

    for (i = 0; i < GIG; ++i) {
        a[i] = 'a';
    }
    
    return 0;
}

