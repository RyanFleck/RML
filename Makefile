CFLAGS = -std=c99 -Wall -g 
LFLAGS = -L/usr/include -ledit -lm -lreadline 

rml: rml.c
	$(CC) $(CFLAGS) -o rml rml.c mpc.c $(LFLAGS) 

.PHONY: format
format:
	astyle -A3 *.c

.PHONY: clean 
clean:
	git clean -f -d
