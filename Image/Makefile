CC=gcc
CFLAGS=-Ifunctions

all: main.o image.o
	$(CC) main.o image.o -o image 

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

image.o: functions/image.c
	$(CC) -c functions/image.c

clean:
	rm -r *.o
	rm image

