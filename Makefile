CC=gcc
CFLAGS=-Wall -Wextra -O2

dark-stash: main.c
	$(CC) $(CFLAGS) -o dark-stash main.c

clean:
	rm -f dark-stash
