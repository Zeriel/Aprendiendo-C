/****************************************************************************
 *                                                                          *
 * Filename: 06-menu.c                                                      *
 *                                                                          *
 * Purpose : Creacion de un menu de usuario en Standard C.                  *
 *                                                                          *
 * History : Fecha                                                          *
 *           16-07-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Un menu en C no difiere mucho de un menu en Pascal, salvo por la sintaxis y por detalles
//como el "break;" que debe llevar cada opcion del caso para poder salir

#include <stdio.h>
#include <conio.h>

int res=9;
char unString;

int main(){
	while (res!=0){
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
	}
	return 0;
}
