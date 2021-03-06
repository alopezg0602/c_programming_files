/*
 ============================================================================
 Name        : maze_project.c
 Author      : Aldo
 Version     :
 Copyright   : Your copyright notice
 Description : C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void push(void);
int  pop(void);
void display(void);

typedef struct stack
{
    int stk[MAXSIZE];
    int top;
}Stack_T;

Stack_T s;

int main ()
{
    int x;              /*columnas*/
    int y;              /*filas*/
    char *ptr_str;
    char temp[99];      /* string temporal para almancenar datos*/

    fgets(temp, 99, stdin);
    x = strtol(temp,&ptr_str,10);
    fgets(temp, 99, stdin);
    y = strtol(temp,&ptr_str,10);

    printf(ANSI_COLOR_RED "\nLas dimensiones del mapa son: %d filas por %d columnas" ANSI_COLOR_RESET,x,y);
    printf("\n %s",ptr_str);

    /*S*/
	return 0;
}

void push ()
{
    int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}
/*  Function to delete an element from the stack */
int pop ()
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf ("poped element is = %dn", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}
