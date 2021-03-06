/*
 ============================================================================
 Name        : Pointer_Ex_20160528.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *reserva(int elementos);

int main()
{

	int **ptr = NULL;
	int c=0,d=0;

	srand (time(NULL));

	/*Se reservan  5 espacios de 32 bits para el arreglo de enteros*/
	ptr = (int *) reserva(5);

	/*En cada espacio de 32 bits se reserva la direccion de otros 5 espacios de memoria
	 *   ptr = direccion de memoria del arreglo que va a barrer las columnas.
	 * (*ptr)= direccion de memoria del arreglo que va a barrer las filas.
	 * */

	for( c=0; c<5; c++)
	{
		*ptr = (int *) reserva(5);
		ptr++;
	}

	/*El apuntador ptr se decrementa para apuntar al ultima columna que compone la matriz*/
	ptr--;

	/*Se procede a llenar el arreglo*/

    for( c=0; c<5; c++)
    {
        for( d=0; d<5; d++)
        {
            **ptr = rand() % 10;
            (*ptr)++;
        }
        ptr--;
    }
    /*El apuntador ptr se incrementa para apuntar a la primera columna que compone la matriz*/
    ptr++;

    /*Se procede a imprimir el arreglo*/

    for( c=0; c<5; c++)
    {
        (*ptr)--;
        for( d=0; d<5; d++)
        {
            printf("\t%d",**ptr);
            (*ptr)--;
        }
        printf("\n");
        ptr++;
    }
    free(ptr);
    getch();
    return 0;
}

int *reserva(int elementos)
{
    int *ptrAux;
    ptrAux = (int *)malloc(elementos*sizeof(int));
    return ptrAux;
}
