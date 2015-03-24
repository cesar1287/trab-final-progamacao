all: main

main: main.o lista.o
	gcc main.o lista.o -o main

main.o: main.c lista.h cores.h
	gcc -g -c main.c

lista.o: lista.c lista.h cores.h
	gcc -g -c lista.c

clean:
	rm -f *~ *.o main

