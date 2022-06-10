all: vm
CC=gcc
CFLAGS=-I.

vm: nvc.o errors.o functions.o
	gcc -o vm nvc.o errors.o functions.o

.PHONY: clean run

run: 
	./vm

clean: 
	rm -rf vm nvc.o errors.o functions.o