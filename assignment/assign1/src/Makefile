CC=gcc
OBJ=simple-shell.o simple-execute.o

SimpleShell: $(OBJ)
		$(CC) -o SimpleShell $(OBJ)

simple-shell.o: simple-shell.c
		$(CC) -c -o simple-shell.o simple-shell.c

simple-execute.o: simple-execute.c
		$(CC) -c -o simple-execute.o simple-execute.c

clean: 
	rm *.o SimpleShell