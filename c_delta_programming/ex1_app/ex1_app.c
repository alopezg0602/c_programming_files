#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef	struct registro{
		char *nombre_libro;
		char *autor;
		int codigo;
		int *anio;
	}registro_t;

typedef	struct estantes{
		char nombre_estante;
		int cantidad_libros;
		registro_t *Libros;
	}estantes_t;

registro_t *reservarMem(void);
void llenarLibro (registro_t *libro);

int main (void)
{
	estantes_t orden_estante[3];
	/*Datos para el Estante A*/
	orden_estante[0].nombre_estante='A';
	orden_estante[0].cantidad_libros=0;
	orden_estante[0].Libros=NULL;

	orden_estante[0].Libros = reservarMem();
	llenarLibro(orden_estante[0].Libros);

/*	orden_estante[0].Libros = (registro_t *) malloc (sizeof(registro_t));
	orden_estante[0].Libros->nombre_libro = "Algebra";
	orden_estante[0].Libros->autor = "Baldor";
	orden_estante[0].Libros->codigo = 123456;
	orden_estante[0].Libros->anio = (int *) malloc(sizeof(int));
	*(orden_estante[0].Libros->anio) = 2016;*/


	printf("Nombre del libro: %s\n", orden_estante[0].Libros->nombre_libro);
	printf("Autor: %s \n", orden_estante[0].Libros->autor);
	printf("Codigo: %d \n", orden_estante[0].Libros->codigo);
	printf("Anio: %d\n", *(orden_estante[0].Libros->anio));

	getch();
	return 0;
}

registro_t *reservarMem(void)
{
	registro_t *aux;
	aux = (registro_t *) malloc (sizeof(registro_t));
	aux->anio = (int *) malloc(sizeof(int));
	return aux;
}

void llenarLibro (registro_t *libro)
{
	printf("\n Digita el nombre del autor: ");
	scanf("%s",libro->autor);
	printf("\n Digita el nombre del libro: ");
	scanf("%s",libro->nombre_libro);
	/*libro->autor = "Algebra";
	libro->nombre_libro = "Baldor";*/
	libro->codigo = 123456;
	*(libro->anio) = 2016;
}
