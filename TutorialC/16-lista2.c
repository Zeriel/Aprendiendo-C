/****************************************************************************
 *                                                                          *
 * Filename: 16-lista2.c                                                    *
 *                                                                          *
 * Purpose : Ejemplo de uso de listas simples en Standard C.                *
 *                                                                          *
 * History : Fecha                                                          *
 *           23-08-2017                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En la parte anterior de lista se vio el manejo basico de las mismas en C. Ahora
//se vera como crear listas segun la demanda del usuario que ingresa informacion.

//IMPORTANTE: Para trabajar con listas por referencia, se debe enviar un puntero que referencia
//al puntero de la lista, es decir, un puntero de puntero. Esto se escribe con dos astericos (**).
//
//

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct Alumno{
	char apellido[15];
	char legajo[10];
	float nota;
	struct Alumno *siguiente;
};

//PROCEDIMIENTOS PROTOTIPADOS

//INSERTAR
void insertar(struct Alumno **lista);

//ELIMINAR
void eliminar(struct Alumno **lista);

//MODIFICAR
void modificar(struct Alumno **lista);

//LISTAR
void listar(struct Alumno *lista);

int main(){
	int resp;
	struct Alumno *L; //Defino la lista.
	L=0; //inicializo L.
	printf("Ejemplo de manejo de una lista general");
	_getch();
	_clrscr();
	resp=9;
	while (resp!=0){
		printf("MENU PRINCIPAL\n");
		printf("-----------------\n");
		printf("\n");
		printf("1) Agregar alumno\n");
		printf("2) Mostrar alumnos\n");
		printf("3) Eliminar alumno\n");
		printf("4) Modificar alumno\n");
		printf("0) Salir");
		printf("\n");
		printf("Elija una opcion: ");
		scanf("%d", &resp);
		_clrscr();
		switch (resp){
			case 1:
				insertar(&L);		//Invoco al procedimiento que inserta un nuevo nodo.
				break;
			case 2:
				listar(L);		//Invoco al procedimiento que lista todos los nodos.
				break;
			case 3:
				eliminar(&L);		//Invoco al procedimiento que elimina un nodo.
				break;
			case 4:
				modificar(&L);	//Invoco al procedimiento que modifica un nodo.
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
		_clrscr();
	}
	return 0;
}

//INSERTAR
void insertar(struct Alumno **lista){
	char apellido[15], legajo[10];
	float nota;

	struct Alumno *aux;		//Defino un auxiliar para no alterar L.
	struct Alumno* nuevo = malloc(sizeof(struct Alumno)); //Creo el primer nodo.
	printf("Ingrese apellido: ");
	scanf("%s", apellido);
	_clrscr();
	printf("Ingrese legajo (formato XX-YYYYY-Z): ");
	scanf("%s", legajo);
	_clrscr();
	printf("Ingrese nota: ");
	scanf("%f", &nota);
	_clrscr();
	strcpy(nuevo->apellido, apellido);	//Asigno cada campo.
	strcpy(nuevo->legajo, legajo);
	nuevo->nota=nota;
	nuevo->siguiente=0;		//El siguiente es NIL.
	if(*lista==0){	//La lista esta vacia.
		*lista=nuevo;
	}
	else{			//No es el primer elemento.
		aux=*lista;		//Asigno a aux la direccion de L, asi opero sobre aux y no sobre L.
		while(aux->siguiente!= 0){	//Repetimos mientras el aux no sea NIL.
            aux=aux->siguiente;		//Nos movemos por la lista.
        }
		aux->siguiente=nuevo;	
	}
}

//ELIMINAR
void eliminar(struct Alumno **lista){
	char legajo[10];

	struct Alumno *act;	//Defino un actual para moverme por L.
	struct Alumno *ant;	//Defino un anterior para poder hacer el enlace si elimino.
	if (*lista==0){
		printf("No hay alumnos cargados");
	}
	else{
		ant=0;			//Anterior debe ser NIL.
		act=*lista;		//Actual debe ser L.
		printf("Ingrese legajo: ");
		scanf("%s", legajo);
		_clrscr();
		while (act!=0 && strcmp(act->legajo,legajo)!=0){ //Mientras no llegue al final de la lista o no encuentre el legajo.
			ant=act;	//Anterior se mueve a Actual.
			act=act->siguiente;	//Actual se mueve a su nodo siguiente.
		}
		if (act==0){	//Si acutal tiene valor NILL, es porque llego al final de la lista y no encontro el legajo.
			printf("No se encontro el alumno");
		}
		else{
			if (ant!=0){//Si anterior no es NILL, quiere decir que no estamos eliminando el primer elemento.
				ant->siguiente=act->siguiente;
			}
			else{		//Si anterior si era NILL, debemos eliminar el primer elemento corriendo la lista L.
				*lista=act->siguiente;
			}
			free(act);	//Liberamos el espacio en memoria ocupado por el nodo que ya sacamos de la lista.
			printf("Alumno: %s eliminado", legajo);
		}
	}
	_getch();
	_clrscr();
}

//MODIFICAR
void modificar(struct Alumno **lista){
	char legajo[10];

	struct Alumno *act;		//Mismo que antes, creo un actual para moverme por la lista L.
	if (*lista==0){			//Control para no pedir datos de forma innecesaria.
		printf("No hay alumnos cargados");
	}
	else{
		act=*lista;			//Asigno a actual la direccion de L.
		printf("Ingrese legajo: ");
		scanf("%s", legajo);
		_clrscr();
		while (act!=0 && strcmp(act->legajo,legajo)!=0){ //Evaluo no llegar al final de la lista o encontrar el legajo.
			act=act->siguiente;	//Me muevo por la lista.
		}
		if (act==0){
			printf("El alumno: %s no existe", legajo);
		}
		else{	//Si la lista no es NIL, encontre el legajo ingresado y procedo a modificar sus datos.
			printf("Ingrese nuevo apellido: ");
			scanf("%s", act->apellido);
			_clrscr();
			printf("Ingrese nuevo legajo: ");
			scanf("%s", act->legajo);
			_clrscr();
			printf("Ingrese nueva nota: ");
			scanf("%f", &act->nota);
			_clrscr();
			printf("Cambio de datos exitoso");
		}
	}
	_getch();
	_clrscr();
}

//LISTAR
void listar(struct Alumno *lista){	//Al enviar la lista por parametros, genero un duplicado que no afectara
	if (lista==0){					//a L.
		printf("No hay alumnos cargados");
		_getch();
	}
	else{
		while (lista!=0){
			printf("Apellido: %s\n", lista->apellido);
			printf("Legajo: %s\n", lista->legajo);
			printf("Nota: %.2f\n", lista->nota);
			printf("----------------------------\n");
			_getch();
			lista=lista->siguiente;	//Puedo moverme por lista porque es una copia de L, no esta referenciada.
	}
	_clrscr();
	}
}
