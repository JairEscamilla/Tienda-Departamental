main.out: main.o menu.o inserciones.o
	gcc -o main.out main.o menu.o inserciones.o -lnsl -lm -lz -lmysqlclient

main.o: main.c headers.h
	gcc -c main.c

menu.o: menu.c 
	gcc -c menu.c

inserciones.o: inserciones.c 
	gcc -c inserciones.c

clean: 
	rm -f *.o