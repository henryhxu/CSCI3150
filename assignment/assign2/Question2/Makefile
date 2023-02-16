CC=gcc 

Scheduler: scheduler-exec.o scheduler-impl.o linkedlist.o queue.o
		$(CC) -o Scheduler scheduler-impl.o scheduler-exec.o linkedlist.o queue.o

scheduler-exec.o: scheduler-exec.c
		$(CC) -c -o scheduler-exec.o scheduler-exec.c

scheduler-impl.o: scheduler-impl.c
		$(CC) -c -o scheduler-impl.o scheduler-impl.c

queue.o: queue.c
		$(CC) -c -o queue.o queue.c

linkedlist.o: linkedlist.c
		$(CC) -c -o linkedlist.o linkedlist.c

clean:
		rm *.o & rm Scheduler