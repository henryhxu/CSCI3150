CC=gcc 

main: main.o fifo.o lru.o
		$(CC) -o main fifo.o lru.o main.o

main.o: main.c
		$(CC) -c -o main.o main.c

fifo.o: fifo.c
		$(CC) -c -o fifo.o fifo.c

lru.o: lru.c
		$(CC) -c -o lru.o lru.c

clean:
		rm *.o & rm main