CC=gcc
CFLAGS=-I

rmlmake: rml.c
	cc -Wall -std=c99 -ledit -lm -lreadline -o rml rml.c mpc.c

