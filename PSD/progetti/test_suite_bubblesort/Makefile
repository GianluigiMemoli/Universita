test:	vettore.o test.o utile.o file_utils.o
	gcc -pthread ./bin/test.o ./bin/vettore.o ./bin/utile.o ./bin/file_utils.o -o test

test.o:	../header/vettore.h ../header/file_utils.h test.c
	gcc -c test.c -o ./bin/test.o

utile.o:	../moduli/utile.c
	gcc -c ../moduli/utile.c -o ./bin/utile.o

vettore.o:	../moduli/vettore.c ../header/utile.h
		gcc -c ../moduli/vettore.c -o ./bin/vettore.o

file_utils.o:	../moduli/file_utils.c
	gcc -c ../moduli/file_utils.c -o ./bin/file_utils.o

clean:
	rm -f test ./bin/vettore.o ./bin/test.o ./bin/file_utils.o ./bin/utile.o
