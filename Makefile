main.out: main.o menu.o inserciones.o actualizaciones.o compra.o desplegar.o eliminar.o
	gcc -o main.out main.o menu.o inserciones.o actualizaciones.o compra.o desplegar.o eliminar.o -lnsl -lm -lz -lmysqlclient

main.o: main.c headers.h conexion.h
	gcc -c main.c 


menu.o: menu.c 
	gcc -c menu.c

inserciones.o: inserciones.c 
	gcc -c inserciones.c

actualizaciones.o: actualizaciones.c 
	gcc -c actualizaciones.c

compra.o: compra.c 
	gcc -c compra.c

desplegar.o: desplegar.c 
	gcc -c desplegar.c 

eliminar.o: eliminar.c 
	gcc -c eliminar.c

clean: 
	rm -f *.o