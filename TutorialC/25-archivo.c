/****************************************************************************
 *                                                                          *
 * Filename: archivo.c                                                      *
 *                                                                          *
 * Purpose : Ejemplo de uso de archivos en Standard C.                      *
 *                                                                          *
 * History : Fecha                                                          *
 *           13-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//La declaración de un archivo es similar a la de un puntero (ya que en realidad es un puntero de
//archivo):
//
//	FILE *nombreArchivo;
//
//Para abrir un archivo, usamos la función "fopen". La misma puede tener argumentos que indican
//la manera en la que se abrirá el archivo:
//
//	r  - abre en modo lectura.
//	w  - abre en modo escritura. Si existe un archivo lo sobrescribe.
//	a  - abre en modo concatenar (append). Si el archivo no existe, lo crea.
//	r+ - abre en modo lectura y escritura, comienza al principio del archivo.
//	w+ - abre en modo lectura y escritura (sobreescrive el archivo).
//	a+ - abre en modo lectura y escritura. Si el archivo existe lo abre en lectura y concatenación (append).
//
//Si hay un error en la apertura del archivo (sea que no existe, que esta protegido contra escritura, etc)
//la función fopen retornará 0 (el puntero NULL).
//
//La concatenacion (append) permite agregar nueva información al final del archivo. Esto evita tener que 
//buscar el final del archivo manualmente para agregar información.
//
//
//Para leer o escribir en un archivo, se usan las funciones fwrite y fread. La sintaxis en ambos casos es:
//
//	fwrite/fread(&dato, tamaño del dato, cantidad de elementos, nombre del archivo);
//
//-Dato: 		Puede ser un tipo nativo, un array o un registro, depende de lo que queramos almacenar.
//-Tamaño:		Es el tamaño en bites (sizeof) de lo que queramos almacenar.
//-Cantidad:	En caso de un array, especificamos su tamaño. Si no es un array será 1.
//-Nombre:		Es el nombre del archivo al que queremos aplicar la operación. 
//
//Para cerrar un archivo, se usa la funcion "fclose", la cual retorna 0 si logro cerrarlo, o EOF si hubo
//algun error durante la operacion. 
//
//IMPORTANTE:
//Existen otras funciones para leer y escribir en un archivo, las cuales funcionan a nivel caracter o string. 
//FWRITE y FREAD son llamadas funciones binarias y deben usarse solo si se opera con bloques de memoria (binarios),
//por ejemplo structs o arrays. Como en Pascal la minima unidad a escribir en un archivo es un registro,
//respetaremos eso en este tutorial.
//Operar con funciones binarias nos generara un archivo binario, el cual puede entender las funciones
//de archivos de acceso directo.

//Como consejo final, uno siempre deberia validar mediante if que las funciones de I/O resulten exitosas tras correrlas,
//ya que este tipo de funciones pueden fallar. Estas mismas validaciones son las que arrojan el warning de "Unreachable
//code", ya que es una comparacion "constante" para C, pero la funcion puede ser 0 si hubo error.


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Persona{
	char nombre[20];
	int edad;
	int dni;
};

int main(){
	FILE *archivo;	//Defino mi archivo de salida
	int i;			//Lo usare mas adelante para numerar cada elemento del archivo
	 
	//Lo abro en modo escritura
	archivo = fopen ("archivos/ejemplo1.dat", "wb");
	//Nota: si en lugar de usar "w" usaramos "a", cada ejecucion de esta aplicacion acumularia datos
	//en el archivo. Pueden cambiarlo y verificarlo en la impresion de mas abajo.
	if (archivo == NULL)	//Si es NULL, hubo un error
	    printf("Error abriendo el archivo\n");
	else{
		//Defino dos registros Persona para cargar
		struct Persona persona1 = {"Ejemplo", 20, 11111111};
		struct Persona persona2 = {"Ejemplo2", 22, 22222222};

		//Escribo los registros en el archivo
	    fwrite (&persona1, sizeof(struct Persona), 1, archivo);
	    fwrite (&persona2, sizeof(struct Persona), 1, archivo);
		//&persona1 es el dato a escribir - sizeof(struct Persona) su tamaño - 1 porque no es array
		//- archivo es el archivo destino
	     
	    if(fwrite != 0) 
	        printf("Los datos se escribieron de forma correcta");
	    else
	        printf("Error al escribir en el archivo\n");
	}
	_getch();
	_clrscr();
	fclose(archivo);	//Cierro el archivo

	//Ya cargamos el archivo (podemos corroborarlo abriendo el mismo desde el SO), ahora procederemos a leer su
	//informacion

    //Lo abro en modo lectura
    archivo = fopen ("archivos/ejemplo1.dat", "rb");
    if (archivo == NULL)
    {
        printf("Error abriendo el archivo\n");
    }
	else{
		//Defino un registro para usar de lectura
		struct Persona datoLectura;
	    //Leo los datos del archivo hasta el EOF
		printf("Datos cargados en el archivo:\n-----------------\n");
		i=1;
	    while(fread(&datoLectura, sizeof(struct Persona), 1, archivo)){
			//Este while funciona porque, de no leer nada, fread retorna 0 (false)
	        printf ("Elemento %d:\n--Nombre = %s\n--Edad = %d\n--DNI: %d\n\n", i, datoLectura.nombre,
	        datoLectura.edad, datoLectura.dni);
			i++;
			_getch();
		}

	}
	_getch();
	_clrscr();
	fclose(archivo);	//Cierro el archivo
    return 0;
}
