listest.exe:	item.o c_list.o listest.o
	gcc ./bin/item.o ./bin/c_list.o ./bin/listest.o -o listest.exe

listest.o:	../header/c_list.h ../header/item.h listest.c
	gcc -c listest.c -o ./bin/listest.o

item.o:	../header/item.h ../moduli/item.c
	gcc -c ../moduli/item.c -o ./bin/item.o


c_list.o:	../header/c_list.h ../header/item.h ../moduli/c_list.c
	gcc -c ../moduli/c_list.c -o ./bin/c_list.o

clean:
	rm -f listest.exe bin/*
