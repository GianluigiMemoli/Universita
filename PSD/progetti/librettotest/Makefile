libtest.exe:	esame.o libretto_array.o libtest.o
	gcc ./bin/esame.o ./bin/libretto_array.o ./bin/libtest.o -o libtest.exe

esame.o:	../moduli/esame.c ../header/esame.h
	gcc -c ../moduli/esame.c -o ./bin/esame.o

libretto_array.o:	../moduli/libretto_array.c ../header/libretto_array.h ../header/esame.h
	gcc -c ../moduli/libretto_array.c -o ./bin/libretto_array.o

libtest.o: libtest.c ../header/libretto_array.h ../header/esame.h
	gcc -c libtest.c -o ./bin/libtest.o

clean:
	rm -f libtest.exe ./bin/*
