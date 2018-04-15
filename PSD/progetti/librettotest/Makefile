libtest.exe:	esame.o libretto.o libtest.o
	gcc ./bin/esame.o ./bin/libretto.o ./bin/libtest.o -o libtest.exe

esame.o:	../moduli/esame.c ../header/esame.h
	gcc -c ../moduli/esame.c -o ./bin/esame.o

libretto.o:	../moduli/libretto.c ../header/libretto.h ../header/esame.h
	gcc -c ../moduli/libretto.c -o ./bin/libretto.o

libtest.o: libtest.c ../header/libretto.h ../header/esame.h
	gcc -c libtest.c -o ./bin/libtest.o

clean:
	rm -f libtest.exe ./bin/*
