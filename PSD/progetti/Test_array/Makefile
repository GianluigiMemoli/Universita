test:	vettore.o test.o
	gcc -pthread ./bin/test.o ./bin/vettore.o -o test

test.o:	../header/vettore.h test.c
	gcc -c test.c -o ./bin/test.o

vettore.o:	../moduli/vettore.c
		gcc -c ../moduli/vettore.c -o ./bin/vettore.o

clean:
	rm -f test ./bin/vettore.o ./bin/test.o
