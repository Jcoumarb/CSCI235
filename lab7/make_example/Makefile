SHELL=/bin/bash
CC = gcc

all: link

hellofunc: hellofunc.c
	gcc -c hellofunc.c

hellomake: hellomake.c
	gcc -c hellomake.c

link: hellofunc hellomake
	gcc -o output hellomake.o hellofunc.o -lm
