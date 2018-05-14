/****************************************************************************
 *                                                                          *
 * Filename: tp4Registro.c                                                  *
 *                                                                          *
 * Purpose : Ejercicios del TP4 de algoritmos en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           19-08-2017														* 
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

#include<stdio.h>
#include<conio.h>

struct hab{					//Defino un registro (structure) para habitacion
	int num;
	int piso;
	char tipo[15];
	float precio;
	char confort[15];
	char estado;
};

struct hab hotel[5];		//Defino un vector de 5 posiciones de tipo hab
int i, resp, num, dias;		//*Notese que para crear una variable tipo registro empleamos la
int cont;					//palabra clave "struct" seguido del tipo de dato y el nombre


int main(){
	//Ejercicio 1: Habitaciones de un hotel
	printf("Ejercicio 1: uso de arreglo de registro");
	_getch();
	_clrscr();
	printf("Iniciando carga de hotel");
	_getch();
	_clrscr();
	for (i=0; i<5; i++){	//Cargo los datos de cada habitacion en cada posicion del arreglo
		printf("Habitacion %d\n", i+1);
		printf("-------------------\n");
		printf("Ingrese numero de habitacion: ");
		scanf("%d", &hotel[i].num);
		_clrscr();
		printf("Ingrese tipo de habitacion: ");
		scanf("%s", hotel[i].tipo);
		_clrscr();
		printf("Ingrese piso de habitacion: ");
		scanf("%d", &hotel[i].piso);
		_clrscr();
		printf("Ingrese confort de habitacion: ");
		scanf("%s", hotel[i].confort);
		_clrscr();
		printf("Ingrese precio de habitacion: ");
		scanf("%f", &hotel[i].precio);
		_clrscr();
		getchar();		//Este getchar absorbe un ENTER que de otro modo ingresaria en el scanf
		printf("Ingrese estado de habitacion (D(disponible)/O(ocupada): ");
		scanf("%c", &hotel[i].estado);
		_clrscr();
	}
	resp=9;
	while (resp!=0){	//Menu principal del sistema
		_clrscr();
		printf("MENU PRINCIPAL: Ejericio administracion hotel\n");
		printf("---------------------------------------------\n");
		printf("\n");
		printf("1) Listar habitaciones disponibles\n");
		printf("2) Estado de habitaciones ordenadas por tipo\n");
		printf("3) Liquidar habitacion\n");
		printf("0) Salir\n");
		printf("\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &resp);
		_clrscr();
		switch (resp){		//Caso para el menu, con sus 4 opciones validas y una rama falsa
			case 1:
				cont=5;		//Contador para saber si no queda ninguna habitacion disponible
				for (i=0; i<5; i++){
					if(hotel[i].estado=='d' || hotel[i].estado=='D'){
						printf("Habitacion: %d\n", i+1);  //i+1 para no empezar de 0
						printf("-----------------\n");
						printf("Numero: %d\n", hotel[i].num);
						printf("Tipo: %s\n", hotel[i].tipo);
						printf("Piso: %d\n", hotel[i].piso);
						printf("Confort: %s\n", hotel[i].confort);
						printf("Precio por dia: %.2f\n", hotel[i].precio);
						printf("\n");
						_getch();
					}
					else{
						cont--;		//Restamos 1 al contador por cada habitacion ocupada
					}
				}
				if (cont==0){		//Si cont es 0 es porque ninguna habitacion estaba disponible
					printf("No hay habitaciones disponibles");
					_getch();
				}
				break;
			case 2:			//Esta parte requiere saber ordenamiento de arreglo, que es mas avanzado
				printf("Esta opcion requiere conocimientos de ordenamiento de vector");
				_getch();
				break;
			case 3:
				printf("Ingrese numero de habitacion a liquidar: ");
				scanf("%d", &num);
				i=0;
				while (i<5 && hotel[i].num!=num){
					i++;
				}
				if (i<5){
					if (hotel[i].estado=='o' || hotel[i].estado=='O'){
						printf("Ingrese dias de estadia: ");
						scanf("%d", &dias);
						_clrscr();
						printf("FACTURACION\n");
						printf("\n");
						printf("Habitacion numero: %d\n", num);
						printf("Dias de estadia: %d\n", dias);
						printf("Precio por dia: %.2f", hotel[i].precio);
						printf("\n");
						printf("Monto total: .............%.2f $", hotel[i].precio*dias);
						hotel[i].estado='D';
						_getch();
					}
					else{
						printf("La habitacion %d no esta ocupada", num);
						_getch();
					}
				}
				else{
					printf("Ingreso un numero de habitacion inexistente");
					_getch();
				}
				break;
			case 0:
				printf("Terminando ejecucion");
				_getch();
				break;
			default:
				printf("Opcion incorrecta");
				_getch();
				break;
		}
	}
}
