CFLAGS = -Wall -g
LFLAGS = -L/usr/include -ledit -lm -lreadline 

rml: rml.c
	$(CC) $(CFLAGS) -o rml rml.c mpc.c $(LFLAGS) 

