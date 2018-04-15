listest.exe:	item.o list.o listest.o
	gcc ./bin/item.o ./bin/list.o ./bin/listest.o -o listest.exe

listest.o:	../header/list.h ../header/item.h listest.c
	gcc -c listest.c -o ./bin/listest.o

item.o:	../header/item.h ../moduli/item.c
	gcc -c ../moduli/item.c -o ./bin/item.o


list.o:	../header/list.h ../header/item.h ../moduli/list.c
	gcc -c ../moduli/list.c -o ./bin/list.o

clean:
	rm -f listest.exe bin/*
