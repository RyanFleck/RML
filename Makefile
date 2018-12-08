CFLAGS = -std=c99 -Wall -g -I//usr/include
LFLAGS = -ledit -lreadline -lm  

rml: rml.c
	$(CC) $(CFLAGS) -o rml rml.c mpc.c $(LFLAGS) 

