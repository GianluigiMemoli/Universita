puntotest: puntotest.o punto.o
	gcc -lm ./bin/puntotest.o ./bin/punto.o -o puntotest

punto.o:  ../header/punto.h
	gcc -c  ../moduli/punto.c -o ./bin/punto.o

puntotest.o:	puntotest.c ../header/punto.h
	gcc -c puntotest.c -o ./bin/puntotest.o

clean:
	rm -f ./bin/*
