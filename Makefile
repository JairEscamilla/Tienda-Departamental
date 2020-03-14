main.out: main.o menu.o
	gcc -o main.out main.o menu.o -lnsl -lm -lz -lmysqlclient

main.o: main.c headers.h
	gcc -c main.c

menu.o: menu.c 
	gcc -c menu.c

clean: 
	rm -f *.o