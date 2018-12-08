CC=gcc
CFLAGS=-I

rmlmake: rml.c
	cc -Wall -std=c99 -ledit -lm -o rml rml.c mpc.c

