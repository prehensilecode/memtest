#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define GIG 1073741824l

int main(int argc, char** argv)
{
    char   *a = NULL;
    char    mesg[1024];
    size_t  size = 0;
    size_t  i = 0;
    int     ci = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: glom N\n");
        fprintf(stderr, "    where N = no. of gibibytes\n");
        exit(1);
    }

    size = atol(argv[1]);

    /* seed RNG with current time */
    srand(time(NULL));
    printf("number = %d\n", rand());

    printf("Trying to allocate %ld chars (%ld GiB) ...\n", size * GIG, size);
    fflush(stdout);

    for (i = 0; i < 1024; ++i)
        mesg[i] = '\0';

    a = malloc(size * GIG);
    if (a == (char*)NULL) {
        sprintf(mesg, "Cannot allocate %ld chars", size);
        perror(mesg);
    } else {
        printf("Allocated %ld chars for %ld GiB\n", size*GIG, size);
        printf("Filling memory ...");
        for (i = 0; i < size * GIG; ++i) {
            ci = rand();
            a[i] = (char)( (float)ci / (float)RAND_MAX * 93. + 1. );
        }
        printf(" Done\n");
    }

    printf("Freeing memory ...");
    free(a);
    printf(" Done\n");
    
    return 0;
}

