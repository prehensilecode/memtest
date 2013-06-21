#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define GIG     1073741824l
#define HALFGIG 536870912l

#define LIMIT   192

void usage(void)
{
    fprintf(stderr, "Usage: stress N\n");
    fprintf(stderr, "    where N = no. of gigabytes; N <= %d\n", LIMIT);
    fflush(stderr);
}

int main(int argc, char** argv)
{
    char   *a = NULL;
    char    mesg[1024];
    size_t  size = 0;
    size_t  maxsize = 0;

    if (argc != 2) {
        usage();
        exit(1);
    }

    maxsize = atol(argv[1]);
    printf("maxsize = %ld\n\n", maxsize);

    if (maxsize > LIMIT) {
        usage();
        exit(3);
    }

    /* initialize message buffer */
    for (size_t i = 0; i < 1024; ++i)
        mesg[i] = '\0';


    for (size_t n = 0; n < maxsize; ++n) {
        size = n*HALFGIG;

        printf("Trying to allocate %ld chars (%.01f GB) ...\n", size, (float)n/2.);
        fflush(stdout);

        a = (char*)malloc(size);
        if (a == (char*)NULL) {
            sprintf(mesg, "Cannot allocate %ld chars (%.01f GB)", size, (float)n/2.);
            perror(mesg);
        } else {
            printf("Allocated %ld chars (%.01f GB)\n\n", size, (float)n/2.);
        }

        /* loop and write random data */
        for (size_t m = 0; m < size; ++m) {
            a[m] = 'c';
            a[m] = '\0';
            a[m] = 'a';
            a[m] = '\0';
            a[m] = 't';
            a[m] = '\0';
        }

        sleep(2);
    
        free(a);
    }
    
    return 0;
}

