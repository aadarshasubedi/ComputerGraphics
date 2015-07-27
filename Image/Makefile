CC=gcc
CFLAGS=-Ifunctions

all: main.o image.o line.o
	$(CC) main.o image.o line.o -o image

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

image.o: functions/image.c
	$(CC) -c functions/image.c

line.o: functions/line.c
	$(CC) -c functions/line.c

clean:
	rm -r *.o
	rm image
	rm *.ppm