libtest.exe:	esame.o libretto_node.o libtest.o
	gcc ./bin/esame.o ./bin/libretto_node.o ./bin/libtest.o -o libtest.exe

esame.o:	../moduli/esame.c ../header/esame.h
	gcc -c ../moduli/esame.c -o ./bin/esame.o

libretto_node.o:	../moduli/libretto_node.c ../header/libretto_node.h ../header/esame.h
	gcc -c ../moduli/libretto_node.c -o ./bin/libretto_node.o

libtest.o: libtest.c ../header/libretto_node.h ../header/esame.h
	gcc -c libtest.c -o ./bin/libtest.o

clean:
	rm -f libtest.exe ./bin/*
