CC = gcc
CFLAGS = -g -Wall
DEPS = headers.h

all:
	$(CC) *.c -o a.out
clean:
	rm -rf a.out
