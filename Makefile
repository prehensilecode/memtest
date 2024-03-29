CC = gcc
#CFLAGS = -O0 -g -Wall -std=c99
CFLAGS = -O0 -g -Wall

all: glom glom2 glom3 sizes stress stacksmash

clean:
	/bin/rm -f glom glom2 glom3 sizes stress

glom: glom.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@

glom2: glom2.c
	$(CC) $(CFLAGS) -o $@ $<
	strip $@

glom3: glom3.c
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

