#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define GIG     1073741824l
#define HALFGIG 536870912l

#define LIMIT   192
#define STRSIZE 1024

void usage(void)
{
    fprintf(stderr, "Usage: glom2 N\n");
    fprintf(stderr, "    where N = no. of half-gigabytes; N <= %d\n", LIMIT);
    fflush(stderr);
}

int main(int argc, char** argv)
{
    char   *a = NULL;
    char    mesg[STRSIZE];
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
    for (size_t i = 0; i < STRSIZE; ++i)
        mesg[i] = '\0';


    for (size_t n = 0; n <= maxsize; ++n) {
        size = n*HALFGIG;

        printf("Trying to allocate %ld chars (%.01f GB) ...\n", size, (float)n/2.);
        fflush(stdout);

        a = (char*)malloc(size);
        if (a == (char*)NULL) {
            snprintf(mesg, STRSIZE-1, "Cannot allocate %ld chars (%.01f GB)", size, (float)n/2.);
            perror(mesg);
        } else {
            printf("Allocated %ld chars (%.01f GB)\n\n", size, (float)n/2.);
        }

        sleep(2);
    
        free(a);
    }
    
    return 0;
}

