/****************************************************************************
 *                                                                          *
 * Filename: 18-integrador.c                                                *
 *                                                                          *
 * Purpose : Ejemplo de aplicacion de todo lo visto en Standard C.          *
 *                                                                          *
 * History : Fecha                                                          *
 *           25-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Este ejercicio sera una combinacion de todo lo visto hasta ahora, para poner en uso
//todas las herramientas de programacion conocidas con la sintaxis de Standard C.
//
//El enunciado a resolver sera:
//
//  "Realizar una aplicacion que permita dar de alta, modificar, eliminar y mostrar las
//habitaciones de cada piso de un hotel. Cada habitacion del hotel esta compuesta por:
//	-Numero de habitacion (100-199 piso 1, 200-299 piso 2, etc)
//	-Tipo (standard o premium)
//	-Capacidad (2 o 4)
//	-Precio de estadia
//	-Estado (Ocupado/Desocupado)
//
// 	El hotel tiene en total 5 pisos (arreglo). Las habitaciones pueden o no estar habilitadas 
//por lo que no se conoce el numero de habitaciones cargadas.
//
//	La muestra de habitaciones debe permitir elegir si mostrar todas las habitaciones, solo
//las ocupadas o solo las disponibles.
//
//	Ademas, el adminsitrador desea tener un registro de facturacion de cada habitacion que
//estuvo ocupada y fue facturada en el dia y que el mismo se pueda visualizar en todo
//momento. El registro de facturacion estara compuesto por:
//	-Cliente (se almacena el registro con sus datos: Apellido, Nombre, DNI).
//	-Habitacion ocupada.
//	-Total facturado.
//
//	Se debera poder calcular el total recaudado de todas las habitaciones.
//
//	Se debera implementar para la scolucion un menu con opciones para todas las funcionalidades espeficicadas
//por el cliente. Ademas, sera obligatorio el uso de la recursividad en algun modulo."

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//Para limpiar el registro de errores de las warnings por "Old-stryle function definition" usaremos
//la version actualizada de funciones, que es con "void" si no lleva parametros.

//DEFINICION DEL NODO DE LA LISTA HOTEL.
struct Habitacion{
	int num;
	char tipo[15];
	int capacidad;
	float precio;
	char estado;
	struct Habitacion *psig;
};

//DEFINICION DEL REGISTRO CLIENTE
struct Cliente{
	char apellido[15];
	char nombre[15];
	int dni;
};

//DEFINICION DEL NODO DE LA LISTA FACTURACION.
struct Factura{
	struct Cliente c;
	int numHabitacion;
	float facturado;
	struct Factura *psig;
};


//PROCEDIMIENTOS PROTOTIPADOS.------------------------------------------------------------


//---FUNCIONES DE LISTA HOTEL.



//INICIALIZAR.
void inicializar(void);

//CALCULO DE PISO
int calcPiso(int numero);	//Lo usaremos para obtener el piso en base al numero de habitacion.

//EVALUAR HABITACION EXISTENTE.
int existeHab(int num);		//Devolvera 1 si la habitacion ya existe o 0 caso contrario.

//ALTA HABITACION.
void altaHab(void);

//BAJA HABITACION.
void bajaHab(void);

//MODIFICAR HABITACION.
void modiHab(void);

//ASIGNAR HABITACION.
void asignar(void);

//FACTURAR HABITACION.
void facturar(void);

//---FUNCIONES DE LISTA FACTURA.



//AGREGAR FACTURA.
void agregarFactura(int num, float facturado);

//MOSTRAR FACTURACION.
void mostrarF(struct Factura *aux);

//CALCULAR IMPORTE TOTAL.
void importe(struct Factura *aux);

//---FUNCIONES DE MUESTREO.



//HAY OCUPADOS (para evaluar si hay ocupados en el piso).
int hayOcupados(struct Habitacion *h);

//HAY DISPONIBLES.
int hayDisponibles(struct Habitacion *h);

//MOSTRAR GENERICO (Usada por los demas).
void mostrar(struct Habitacion *h);

//MOSTRAR TODAS HABITACIONES
void mostrarT(struct Habitacion *h[5]);

//MOSTRAR SOLO OCUPADAS
void mostrarO(struct Habitacion *h[5]);

//MOSTRAR SOLO DISPONIBLES.
void mostrarD(struct Habitacion *h[5]);


//--FIN PROCEDIMIENTOS.----------------------------------------------------------------------


//VARIABLES GLOBALES.
struct Habitacion *hotel[5];
struct Factura *F;

//MAIN.
int main(){
	int resp=9, respAux;
	inicializar();
	while (resp!=0){
		printf("MENU PRINCIPAL - ADMINISTRACION DE HOTEL\n");
		printf("----------------------------------------------\n");
		printf("\n");
		printf("1) Administrar habitaciones\n");
		printf("2) Asignar habitacion\n");
		printf("3) Facturar habitacion\n");
		printf("4) Mostrar habitaciones\n");
		printf("5) Menu facturacion");
		printf("\n");
		printf("0)Salir\n");
		printf("\n");
		printf("\n");
		printf("Ingrese opcion: ");
		scanf("%d", &resp);
		_clrscr();
		switch(resp){
			//OPCION UNO
			case 1:
				respAux=9;
				while (respAux!=0){
					printf("MENU HABITACIONES - ADMINISTRACION DE HOTEL\n");
					printf("----------------------------------------------\n");
					printf("\n");
					printf("1) Dar de alta habitacion\n");
					printf("2) Dar de baja habitacion\n");
					printf("3) Modificar datos de habitacion\n");
					printf("\n");
					printf("0)Volver\n");
					printf("\n");
					printf("Ingrese opcion: ");
					scanf("%d", &respAux);
					_clrscr();
					switch(respAux){
						case 1:
							altaHab();
							break;
						case 2:
							bajaHab();
							break;
						case 3:
							modiHab();
							break;
						case 0:
							break;
						default:
							printf("ERROR: Opcion incorrecta ingresada");
							_getch();
						break;
					}
					_clrscr();
				}
				break;
			//OPCION DOS
			case 2:
				asignar();
				break;
			//OPCION TRES
			case 3:
				facturar();
				break;
			//OPCION CUATRO
			case 4:
				respAux=9;
				while (respAux!=0){
					printf("MOSTRAR HABITACIONES - ADMINISTRACION DE HOTEL\n");
					printf("----------------------------------------------\n");
					printf("\n");
					printf("1) Mostrar todas las habitaciones\n");
					printf("2) Mostrar todas las habitaciones OCUPADAS\n");
					printf("3) Mostrar todas las habitaciones DISPONIBLES\n");
					printf("\n");
					printf("0)Volver\n");
					printf("\n");
					printf("Ingrese opcion: ");
					scanf("%d", &respAux);
					_clrscr();
					switch(respAux){
						case 1:
							mostrarT(hotel);
							break;
						case 2:
							mostrarO(hotel);
							break;
						case 3:
							mostrarD(hotel);
							break;
						case 0:
							break;
						default:
							printf("ERROR: Opcion incorrecta ingresada");
							_getch();
						break;
					}
					_clrscr();
				}
				break;
			//OPCION CINCO.
			case 5:
				respAux=9;
				while (respAux!=0){
					printf("MENU FACTURACION - ADMINISTRACION DE HOTEL\n");
					printf("----------------------------------------------\n");
					printf("\n");
					printf("1) Listar habitaciones facturadas con respectivos datos\n");
					printf("2) Calcular importe total\n");
					printf("\n");
					printf("0)Volver\n");
					printf("\n");
					printf("Ingrese opcion: ");
					scanf("%d", &respAux);
					_clrscr();
					switch(respAux){
						case 1:
							mostrarF(F);
							break;
						case 2:
							importe(F);
							break;
						case 0:
							break;
						default:
							printf("ERROR: Opcion incorrecta ingresada");
							_getch();
						break;
					}
					_clrscr();
				}				
				break;
			case 0:
				printf("Terminando ejecucion");
				_getch();
				break;
			default:
				printf("ERROR: Opcion incorrecta ingresada");
				_getch();
				break;
		}
		_clrscr();
	}
	return 0;
}


//PROCEDIMIENTOS IMPLEMENTADOS.----------------------------------------------------------


//---FUNCIONES LISTA HOTEL.--------------------------------------------------------------



//INICIALIZAR (Tambien inicializa la lista de facturacion).
void inicializar(void){		//Inicializo cada puntero del arreglo en NIL.
	for (int i=0; i<5; i++){
		hotel[i]=0;
	}
	F=0;
}

//CALCULO DE PISO.
int calcPiso(int numero){
	if (numero>=600 || numero<100){	//Piso incorrecto
		return 5;
	}
	else if (numero>=500){
		return 4;
	}
	else if(numero>=400){
		return 3;
	}
	else if(numero>=300){
		return 2;
	}
	else if(numero>=200){
		return 1;
	}
	else{
		return 0;
	}
}

//EXISTE HABITACION.
int existeHab(int n){
	int i= calcPiso(n);

	struct Habitacion *aux;
	aux=hotel[i];
	while (aux!=0 && aux->num!=n){
		aux=aux->psig;
	}
	if (aux==0){
		return 0;
	}
	else{
		return 1;
	}
}

//ALTA HABITACION.
void altaHab(void){
	int num, cap, i=0;	//i es para el piso de la habitacion. Le doy valor para limpiar la warning.
	float pre;
	char tipo[15];

	struct Habitacion *aux;
	printf("Ingrese numero de habitacion: ");
	scanf("%d", &num);
	_clrscr();
	i= calcPiso(num);	//Calculo en que piso esta la habitacion.
	if (i<5){ 			//Controlo si el numero es correcto.
		if (!existeHab(num)){	//Controlo si la habitacion ya existe. 0 es el FALSE de C.
					printf("Ingrese capacidad de la habitacion (2 o 4): ");
					scanf("%d", &cap);
					_clrscr();
					printf("Ingrese tipo de habitacion (Standard - Premium): ");
					scanf("%s", tipo);
					_clrscr();
					printf("Ingrese precio de estadia por dia: $");
					scanf("%f", &pre);
					_clrscr();
					if (hotel[i]==0){	//Ese piso no tiene habitaciones (primer nodo).
						hotel[i]= (struct Habitacion *) malloc(sizeof(struct Habitacion));
						hotel[i]->num=num;
						hotel[i]->capacidad=cap;
						strcpy(hotel[i]->tipo, tipo);
						hotel[i]->precio=pre;
						hotel[i]->estado='D';	//Disponible porque acabo de habilitarlo.
						hotel[i]->psig=0;		//Puntero siguiente NIL.
					}
					else{		//Ya hay nodos cargados, debo moverme al ultimo.
						aux=hotel[i];
						while (aux->psig!=0){
							aux=aux->psig;
						}
						aux->psig=(struct Habitacion *) malloc(sizeof(struct Habitacion));
						aux=aux->psig;	//Me muevo al nodo que acabo de crear.
						aux->num=num;
						aux->capacidad=cap;
						strcpy(aux->tipo, tipo);
						aux->precio=pre;
						aux->estado='D';
						aux->psig=0;
					}
			}
			else{
				printf("La habitacion: %d ya existe", num);	//La habitacion ya existe.
				_getch();
				_clrscr();
			}
		}
		else{	//Ingreso mal el numero de habitacion.
			printf("ERROR: Ha ingresado un numero de habitacion de piso inexistente\n\n");
			printf("Recuerde:\n\n   100-199 PISO 1\n   200-299 PISO 2\n   300-399 PISO 3\n   400-499 PISO 4\n   500-599 PISO 5");
			_getch();
			_clrscr();
		}
}

//BAJA HABITACION.
void bajaHab(void){
	int num, i=0;

	struct Habitacion *act;
	struct Habitacion *ant;
	printf("Ingrese habitacion a eliminar. NO DEBE ESTAR OCUPADA.\n\n");
	scanf("%d", &num);
	_clrscr();
	i=calcPiso(num);
	if (i>4){
		printf("ERROR: Numero incosistente con los pisos del hotel.");
	}
	else{
		act=hotel[i];
		ant=0;
		while (act!=0 && act->num!=num){
			ant=act;
			act=act->psig;
		}
		if (act==0 || act->estado=='O'){
			printf("La habitacion %d no existe o esta ocupada.", num);
		}
		else{
			if (ant!=0){	//No es el primer nodo.
				ant->psig=act->psig;
			}
			else{			//Es el primer nodo.
				hotel[i]=hotel[i]->psig;
			}
			free(act);
			printf("Habitacion %d eliminada.", num);
		}
	}
	_getch();
	_clrscr();
}

//MODIFICAR HABITACION.
void modiHab(void){
	int num, i=0;
	char tipo[15];

	struct Habitacion *aux;
	printf("Ingrese habitacion a modificar. NO DEBE ESTAR OCUPADA.\n\n");
	scanf("%d", &num);
	_clrscr();
	i=calcPiso(num);
	if (i>4){
		printf("ERROR: Numero incosistente con los pisos del hotel.");
	}
	else{
		aux=hotel[i];
		while (aux!=0 && aux->num!=num){
			aux=aux->psig;
		}
		if (aux==0 || aux->estado=='O'){
			printf("La habitacion %d no existe o esta ocupada.", num);
		}
		else{
			printf("DATOS ACUTALES:\n\n");
			printf("Numero: %d\nCapacidad: %d\nTipo: %s\nPrecio: %.2f\n\n", aux->num, aux->capacidad, aux->tipo, aux->precio);
			_getch();
			_clrscr();
			printf("Ingrese nuevo numero: ");
			scanf("%d", &aux->num);
			_clrscr();
			printf("Ingrese nueva capacidad: ");
			scanf("%d", &aux->capacidad);
			_clrscr();
			printf("Ingrese nuevo tipo: ");
			scanf("%s", tipo);
			strcpy(aux->tipo, tipo);
			_clrscr();
			printf("Ingrese nuevo precio: ");
			scanf("%f", &aux->precio);
			_clrscr();
			printf("DATOS MODIFICADOS:");
		}
	}
	_getch();
	_clrscr();
}

//ASIGNAR HABITACION.
void asignar(void){
	int cap, i=0;
	char tipo[15], encontro='n';

	struct Habitacion *aux;
	printf("Ingrese tipo de habitacion: ");
	scanf("%s", tipo);
	_clrscr();
	printf("Ingrese capacidad deseada (2-4): ");
	scanf("%d", &cap);
	_clrscr();
	aux=hotel[i];
	while ((encontro=='n') && (i<5)){
		if (aux==0){		//Llegue al final del piso.
			i++;			//Cambio de piso.
			aux=hotel[i];	//Actualizo mi lista auxiliar.
		}
		else{	//Sigo recorriendo el piso
			if(aux->estado=='D' && aux->capacidad==cap && strcmp(aux->tipo,tipo)==0){
				encontro='s';	//Si se dan las condiciones, encontre habitacion
			}
			else{	//La habitacion no servia, me muevo a la siguiente.
				aux=aux->psig;
			}
		}
	}
	if (i==5){	//Recorri los 5 pisos y no encontre habitacion.
		printf("No hay habitacion disponible con las caracteristicas solicitadas");
	}
	else{	//Encontre habitacion.
		printf("Habitacion asignada: %d", aux->num);
		aux->estado='O';
	}
	_getch();
	_clrscr();
}

//FACTURAR HABITACION.
void facturar(void){
	int num, i, dias;

	struct Habitacion *aux;
	printf("Ingrese numero de habitacion a facturar: ");
	scanf("%d", &num);
	i=calcPiso(num);
	_clrscr();
	if (i>4){	//Evaluo si ingreso una habitacion posible.
		printf("El numero de habitacion que ingreso no corresponde a ningun piso");
		_getch();
	}
	else{		//Puede ser que la habitacion exista.
		aux=hotel[i];
		while (aux!=0 && aux->num!=num){
			aux=aux->psig;
		}
		if (aux==0){	//No existe la habitacion.
			printf("No existe habitacion con numero: %d", num);
			_getch();
		}
		else{
			if(aux->estado=='D'){	//Compruebo que sea una habitacion valida para facturar.
				printf("La habitacion %d no esta ocupada. No puede facturarse.", num);
				_getch();
			}
			else{
				printf("Ingrese cantidad de dias de estadia: ");
				scanf("%d", &dias);
				_clrscr();
				printf("PRECIO DE ESTADIA POR DIA:...%.2f\n", aux->precio);
				printf("CANTIDAD DE DIAS:............%d\n", dias);
				printf("TOTAL A FACTURAR:............$%.2f\n", aux->precio*dias);
				aux->estado='D';	//La vuelvo a poner en disponible.
				_getch();
				_clrscr();
				agregarFactura(aux->num, aux->precio*dias);
			}
		}
	}
	_clrscr();
}

//---FUNCIONES DE LISTA FACTURA.----------------------------------------------------------



//AGREGAR FACTURA A LISTA.
void agregarFactura(int num, float facturado){
	struct Factura *aux;
	struct Cliente c;	//Creo un cliente para la factura
	printf("Ingrese datos del cliente\n");
	printf("Apellido: ");
	scanf("%s", c.apellido);
	_clrscr();
	printf("Nombre: ");
	scanf("%s", c.nombre);
	_clrscr();
	printf("DNI: ");
	scanf("%d", &c.dni);
	_clrscr();
	if (F==0){	//No hay facturas cargadas.
		F=(struct Factura *) malloc(sizeof(struct Factura));
		F->c=c;
		F->numHabitacion=num;
		F->facturado=facturado;
		F->psig=0;
	}
	else{		//Ya hay al menos una factura cargada.
		aux=F;
		while (aux->psig!=0){
			aux=aux->psig;
		}
		aux->psig=(struct Factura *) malloc(sizeof(struct Factura));
		aux=aux->psig;
		aux->c=c;
		aux->numHabitacion=num;
		aux->facturado=facturado;
		aux->psig=0;
	}
}

//MOSTRAR FACTURAS.
void mostrarF(struct Factura *aux){
	int i=1;
	while(aux!=0){
		printf("FACTURA N°: %d\n", i);
		printf("-----------------\n");
		printf("HABITACION: %d\n", aux->numHabitacion);
		printf("IMPORTE: $%.2f\n\n", aux->facturado);
		printf("DATOS CLIENTE:\n");
		printf("   Nombre: %s\n   Apellido: %s\n   DNI: %d\n", aux->c.nombre, aux->c.apellido, aux->c.dni);
		_getch();
		i++;
		aux=aux->psig;
	}
	_clrscr();
}

//CALCULAR IMPORTE TOTAL.
void importe(struct Factura *aux){
	float total=0;

	while(aux!=0){
		total+=aux->facturado;	//el += sirve para autoincrementar acumuladores con otro valor.
		aux=aux->psig;
	}
	printf("TOTAL FACTURADO:...........$%.2f", total);
	_getch();
	_clrscr();
}

//---FUNCIONES DE MUESTREO.---------------------------------------------------------------



//COMPROBAR SI EL PISO TIENE OCUPADOS.
int hayOcupados(struct Habitacion *h){
	char encontro='n';	//Para saber si encontro, se inicializara en falso.
	while (h!=0){
		if (h->estado=='O'){
			encontro='s';
		}
		h=h->psig;
	}
	if (encontro=='s'){
		return 1;	//Retorna TRUE.
	}
	else{
		return 0;	//Retorna FALSE.
	}
}

//COMPROBAR SI EL PISO TIENE DISPONIBLES
int hayDisponibles(struct Habitacion *h){
	char encontro='n';	//Para saber si encontro, se inicializara en falso.
	while (h!=0){
		if (h->estado=='D'){
			encontro='s';
		}
		h=h->psig;
	}
	if (encontro=='s'){
		return 1;	//Retorna TRUE.
	}
	else{
		return 0;	//Retorna FALSE.
	}
}

//MOSTRAR GENERICO (Usado por los demas).
void mostrar(struct Habitacion *h){
	printf("Habitacion numero:   %d\n", h->num);
	printf("Capacidad:           %d\n", h->capacidad);
	printf("Tipo:                %s\n", h->tipo);
	printf("Precio de estadia:   %.2f\n", h->precio);
	if (h->estado=='O'){
		printf("Estado:              OCUPADO\n");
	}
	else{
		printf("Estado:              DISPONIBLE\n");
	}
	_getch();
	printf("\n");
}

//MOSTRAR TODOS.
void mostrarT(struct Habitacion *h[5]){
	struct Habitacion *aux; //Para recorrer cada "piso" (h[i]) sin perder la raiz.
	for (int i=0; i<5; i++){
		aux=h[i];			//Le asigno a aux la raiz en v[i] asi puedo recorrer la lista.
		if(aux!=0){			//Compruebo que el piso no este en NIL.
			printf("Listando habitaciones del piso: %d\n", i+1);
			printf("--------------------------------------\n");
			while (aux!=0){
				mostrar(aux);
				aux=aux->psig;
			}
			_clrscr();
		}
	}
}

//MOSTRAR OCUPADOS.
void mostrarO(struct Habitacion *h[5]){
	struct Habitacion *aux; //Para recorrer cada "piso" (h[i]) sin perder la raiz.
	for (int i=0; i<5; i++){
		aux=h[i];				//Le asigno a aux la raiz en v[i] asi puedo recorrer la lista.
		if (aux!=0){
			if (hayOcupados(aux)){	//Comprueba que en ese piso haya habitaciones ocupadas que mostrar.
				printf("Listando habitaciones del piso: %d\n", i+1);
				printf("--------------------------------------\n");
				while (aux!=0){
					if (aux->estado=='O'){	//Como se que alguna es ocupada, la filtro.
						mostrar(aux);
					}
					aux=aux->psig;
				}
				_clrscr();
			}
		}
	}
}

//MOSTRAR DISPONIBLES.
void mostrarD(struct Habitacion *h[5]){
	struct Habitacion *aux; //Para recorrer cada "piso" (h[i]) sin perder la raiz.
	for (int i=0; i<5; i++){
		aux=h[i];				//Le asigno a aux la raiz en v[i] asi puedo recorrer la lista.
		if (aux!=0){
			if (hayDisponibles(aux)){	//Comprueba que en ese piso haya habitaciones disponibles que mostrar.
				printf("Listando habitaciones del piso: %d\n", i+1);
				printf("--------------------------------------\n");
				while (aux!=0){
					if (aux->estado=='D'){	//Como se que alguna es ocupada, la filtro.
						mostrar(aux);
					}
					aux=aux->psig;
				}
				_clrscr();
			}
		}
	}
}
