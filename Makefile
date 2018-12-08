
rmlmake: rml.c
	gcc -Wall -std=c99 -ledit -lm -lreadline -o rml rml.c mpc.c

