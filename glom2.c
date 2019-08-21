#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define GIG     1073741824l
#define HALFGIG 536870912l
#define QUARTERGIG 268435456l

#define LIMIT   512
#define STRSIZE 1024

void usage(void)
{
    fprintf(stderr, "Usage: glom2 N\n");
    fprintf(stderr, "    where N = no. of quarter-gigabytes; N <= %d\n", LIMIT);
    fflush(stderr);
}

int main(int argc, char** argv)
{
    char   *a = NULL;
    char    mesg[STRSIZE];
    size_t  size = 0;
    size_t  maxsize = 0;
    size_t  n = 0;
    size_t  i = 0;
    size_t  p = 0;
    int     ci = 0;

    if (argc != 2) {
        usage();
        exit(1);
    }

    maxsize = atol(argv[1]);
    printf("maxsize = %ld = %.02f GiB\n\n", maxsize, (float)maxsize/4.);

    if (maxsize > LIMIT) {
        usage();
        exit(3);
    }

    /* initialize message buffer */
    for (i = 0; i < STRSIZE; ++i)
        mesg[i] = '\0';

    /* seed RNG with current time */
    srand(time(NULL));
    printf("number = %d\n", rand());


    for (n = 0; n <= maxsize; ++n) {
        size = n*HALFGIG;

        printf("Trying to allocate %ld chars (%.02f GB) ...\n", size, (float)n/4.);
        fflush(stdout);

        a = (char*)malloc(size);
        if (a == (char*)NULL) {
            snprintf(mesg, STRSIZE-1, "Cannot allocate %ld chars (%.02f GB)", size, (float)n/4.);
            perror(mesg);
        } else {
            printf("Allocated %ld chars (%.02f GB)\n", size, (float)n/4.);
            /* fill the array with random chars 
             * there are 94 printable ASCII chars, 33--126 */
            printf("Filling array ...");
            for (p = 0; p < size; ++p) {
                ci = rand();
                a[p] = (char)( (float)ci / (float)RAND_MAX * 93. + 1. );
            }
            printf(" Done\n\n");
        }

        usleep((unsigned int)750000);
    
        free(a);
    }
    
    return 0;
}

