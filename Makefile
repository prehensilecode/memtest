CC = gcc
#CFLAGS = -O0 -g -Wall -std=c99
CFLAGS = -O0 -g -Wall

all: glom glom2 sizes stress stacksmash ascii

clean:
	/bin/rm -f glom glom2 sizes stress

glom: glom.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@

glom2: glom2.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@

sizes: sizes.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@

stress: stress.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@

stacksmash: stacksmash.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@

ascii: ascii.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@
