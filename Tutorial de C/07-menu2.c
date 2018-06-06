/****************************************************************************
 *                                                                          *
 * Filename: 07-menu.c                                                      *
 *                                                                          *
 * Purpose : Creacion de un menu de usuario en Standard C usando Do..While. *
 *                                                                          *
 * History : Fecha                                                          *
 *           10-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Igual que el ejemplo de menu anterior, con la diferencia que ahora emplearemos un
//do..while para ser más eficientes con el código.

#include <stdio.h>
#include <conio.h>

int res;	
char unString;

int main(){
	do{		//Es un Repetir Hasta, la condición va al final
		_clrscr();
		printf("MENU PRINCIPAL\n");
		printf("-----------------\n");
		printf("1) Opcion 1 del menu\n");
		printf("2) Opcion 2 del menu\n");
		printf("3) Opcion 3 del menu\n");
		printf("4) Opcion 4 del menu\n");
		printf("0) Salir\n");
		scanf("%d", &res);
		_clrscr();
		switch (res){
			case 1:
				printf("Opcion 1 elegida");
				break;   //El break delimita cada opcion del caso
			case 2:
				printf("Opcion 2 elegida");
				break;
			case 3:
				printf("Opcion 3 elegida");
				break;
			case 4: 
				printf("Opcion 4 elegida");
				break;
			case 0:
				printf("Opcion 0 elegida. Terminando ejecucion");
				break;
			default:	//Es el "otherwise" de pascal
				printf("Opcion incorrecta");
				break;
		}
		_getch();
	} while (res!=0);	//Evalúo la condición
	return 0;
}
