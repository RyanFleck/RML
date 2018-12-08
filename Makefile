CFLAGS = -std=c99 -Wall -g
LFLAGS = -ledit -lreadline -lm  

rml: rml.c
	$(CC) $(CFLAGS) $(LFLAGS) rml.c mpc.c -o rml 

