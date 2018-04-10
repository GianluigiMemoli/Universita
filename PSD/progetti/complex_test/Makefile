run:	complex.o	run.o
	gcc -pthread ./bin/complex.o	./bin/run.o -o run

run.o:	../header/complex.h	run.c
	gcc -c run.c -o ./bin/run.o

complex.o:	../moduli/complex.c
	gcc -c ../moduli/complex.c -o ./bin/complex.o

clean:
	rm -f run ./bin/*
