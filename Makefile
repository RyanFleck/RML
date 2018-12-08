CFLAGS = -std=c99 -Wall -g
LFLAGS = -ledit -lreadline -lm  

rml: rml.c
	$(CC) $(CFLAGS) -o rml rml.c mpc.c $(LFLAGS) 

