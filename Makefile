main.out: main.o menu.o inserciones.o actualizaciones.o
	gcc -o main.out main.o menu.o inserciones.o actualizaciones.o -lnsl -lm -lz -lmysqlclient

main.o: main.c headers.h conexion.h
	gcc -c main.c 


menu.o: menu.c 
	gcc -c menu.c

inserciones.o: inserciones.c 
	gcc -c inserciones.c

actualizaciones.o: actualizaciones.c 
	gcc -c actualizaciones.c

clean: 
	rm -f *.o