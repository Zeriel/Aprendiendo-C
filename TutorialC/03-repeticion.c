/****************************************************************************
 *                                                                          *
 * Filename: 03-repeticion.c                                                *
 *                                                                          *
 * Purpose : Ejemplo de uso de repetición en Standard C.                    *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-07-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//REPETICION INCONDICIONAL
//
//La repeticion incodicional en C lleva la siguiente estructura:
//
//	for(valorInicial; condicionSalida; operacion)   Notese la separacion con punto y coma (;)
//
//REPETICION CONDICIONAL
//
//---WHILE
//No difiere practicamente del WHILE de Pascal.
//
//---DO..WHILE
//No difiere practicamente del REPEAT UNTIL de Pascal.

#include <stdio.h>
#include <conio.h>

int main(){
	int i;
    /* Repeticion incondicional simple de 1 a 10*/
	printf("Repeticion incondicional de 1 a 10\n");
    for ( i = 1; i <= 10; i++ ) {   
        printf( "%d\n", i );
		_getch();
    }
	printf("Terminando repeticion incodicional\n");
    _getch();
	_clrscr();
	/* Mismo codigo para una repeticion condicional */
	printf("Repeticion condicional de 1 a 10 con WHILE simple\n");
	i = 1; 
 	while ( i < 11 ) {
    	printf( "%d\n", i );
     	i++;             /* Incremento i */
		_getch();
 	}
	printf("Terminando repeticion codicional WHILE\n");
 	_getch();
	_clrscr();
	/* Repeticion condicional con DO..WHILE */
	printf("Repeticion condicional de 1 a 10 con DO..WHILE\n");
	i = 1;  
 	do {
    	printf( "%d\n", i );
     	i++;             /* Incremento i */
		_getch();
 	} while ( i < 11 );
	printf("Terminando repeticion codicional WHILE\n");
 	_getch();
	_clrscr();
	return 0;
}
