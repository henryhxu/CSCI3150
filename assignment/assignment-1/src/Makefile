CC=gcc
OBJ=simple-shell.o simple-execute.o
OBJGRADING=simple-shell-grading.o simple-execute.o
TARGETGRADING=SimpleShellGrading

SimpleShell: $(OBJ)
		$(CC) -o SimpleShell $(OBJ)

simple-shell.o: simple-shell.c
		$(CC) -c -o simple-shell.o simple-shell.c

simple-execute.o: simple-execute.c
		$(CC) -c -o simple-execute.o simple-execute.c

SimpleShellGrading: $(OBJGRADING)
		$(CC) -o $(TARGETGRADING) $(OBJGRADING) -w

simple-shell-grading.o: ./simple-shell-grading.c
		$(CC) -c -o simple-shell-grading.o ./simple-shell-grading.c -w 

clean: 
	rm *.o SimpleShell
	rm *.o SimpleShellGrading

