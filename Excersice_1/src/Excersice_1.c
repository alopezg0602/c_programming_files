/*
 ============================================================================
 Name        : Excersice_1.c
 Author      : Aldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<conio.h>
#include <stdlib.h>


void ordAscending(int *ptr_vector, int n);
void displayArray(int *ptr_to_array,int i);
void exerciseCode_0(void);
void exerciseCode_1(void);
void exerciseCode_2(void);
int* readData(int elements);
int *reserva(int elementos);

#define EXERCISE_LIST\
	  /**********(Exercise Description)****/       \
	DISPLAY_LIST("0: Compare two numbers \n")\
	DISPLAY_LIST("1: Even or Odd \n")\
	DISPLAY_LIST("2: Compare three numbers \n" )\
	DISPLAY_LIST("4: To exit \n" )\

#define FUNCTION_LIST\
	  /*********(ID , Function)*/\
	FUNCTION_MEM(0,exerciseCode_0)\
	FUNCTION_MEM(1,exerciseCode_1)\
	FUNCTION_MEM(2,exerciseCode_2)\

#define DISPLAY_LIST(label) \
		printf(label);\

#define FUNCTION_MEM(id,function)\
	case id:\
	{ \
		function(); \
		break; \
	} \

int main(void) {
	int selector=0;
	printf("Choose one exercise from below list to execute: \n");
	EXERCISE_LIST
	printf("Enter your selection: ");
	scanf("%d",&selector);
	switch (selector)
	{
		FUNCTION_LIST

	   default:
	      /*End the program*/
	      break;
	}
	getch();
	return 0;
}

void ordAscending(int *ptr_vector, int n)
{
	int interruptor = 1;
	int *ptr_store=ptr_vector;
	int *ptr_aux=ptr_vector;
	ptr_aux++;
	int mem=0;

	int pasada, j;
	/*ordering cycle*/
	for(pasada = 0; ((pasada < n-1) && interruptor); pasada++)
	{
		interruptor = 0;
		for (j=0; j<n-pasada -1;j++)
		{
			if(*ptr_vector > *(ptr_aux))
			{
				//change if are not in the required sequence
				interruptor = 1;
				mem=*ptr_vector;
				*ptr_vector = *ptr_aux;
				*ptr_aux=mem;
			}
			ptr_vector++;
		    ptr_aux++;
		}
		ptr_vector=ptr_store;
		ptr_aux=ptr_vector;
		ptr_aux++;
	}
}

void displayArray(int *ptr_to_array,int i)
{
	for(i=0;i<5;i++)
	{
		printf("%d ", *ptr_to_array);
		ptr_to_array++;
	}
	printf("\n");
}

void exerciseCode_0(void)
{
	printf("%s\n",__FUNCTION__);
	int i=5;
	int a[5]={20,40,50,30,80};
	printf("Arreglo Inicial 2 \n");
	displayArray(&a[0],i);
	ordAscending(&a[0],i);
	printf("\n Arreglo Final 2 \n");
	displayArray(&a[0],i);
}

void exerciseCode_1(void)
{
	/*LOCAL VARIABLES*/
	int* ptr_local=NULL;
	int var_temp=0;
	ptr_local = readData(2);
	var_temp=*(++ptr_local);
	ptr_local--;
	/*FUCNTION IMPLEMENTATION*/
	printf("%s\n",__FUNCTION__);
	if((*ptr_local) > var_temp)
	{
		printf("\nEl numero mayor es: %d",*ptr_local);
	}
	else if (*ptr_local < var_temp)
	{
		printf("\nEl numero mayor es: %d",var_temp);
	}
	else
	{
		printf("\n Los numeros son iguales");
	}
	free(ptr_local);
}

void exerciseCode_2(void)
{
	int k=0,elements=0,residual=0;
	int *ptr_to_vector=NULL;
	printf("%s\n",__FUNCTION__);
	printf("Digita el numero de elementos a leer: ");
	scanf("%d",&elements);
	ptr_to_vector = readData(elements);

	for(k=0;k<elements;k++)
	{
		residual=(*ptr_to_vector)%2;
		if(residual==0)
		{
			printf("\nElemento[%d] = %d --> PAR",k,*ptr_to_vector);
		}
		else
		{
			printf("\nElemento[%d] = %d --> IMPAR",k,*ptr_to_vector);
		}
		ptr_to_vector++;
	}
	free(ptr_to_vector);
}

int* readData(int elements)
{
   int k=0;
   int *ptr_to_array=NULL;
   int *ptr_aux=NULL;

   ptr_to_array=reserva(elements);
   ptr_aux=ptr_to_array;

   for (k=0; k<elements; k++)
   {
	  printf("\nCaptura Elemento[%d] = ",k+1);
	  scanf("%d", ptr_to_array);
	  ptr_to_array++;
   }

return ptr_aux;
}

int *reserva(int elementos)
{
    int *ptrAux;
    ptrAux = (int *)malloc(elementos*sizeof(int));
    return ptrAux;
}
