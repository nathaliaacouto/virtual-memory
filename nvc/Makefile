all: garbage
CC=gcc
CFLAGS=-I.

garbage: nvc.o errors.o functions.o
	gcc -o garbage nvc.o errors.o functions.o

.PHONY: clean run

run: 
	./garbage

clean: 
	rm -rf garbage nvc.o errors.o functions.o