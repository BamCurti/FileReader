/*
 * main.c
 *
 *  Created on: 25 abr. 2020
 *      Author: Edgar Vallejo Curti
 */

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "stack.h"
#include "lector.h"

int main(){
	setbuf(stdout, NULL);
	int menu = 0;
	Stack anterior = stack_create();
	Stack siguiente = stack_create();

	Archivo reciente = NULL;

	int nArchivos = 0;

	while(menu != 2){
		printf("1)Abrir Archivo\n"
				"2)Salir\n");
		if(nArchivos >= 1)
			printf("3)Mostrar reciente\n"
					"4)Mostrar Anterior\n"
					"5)Mostrar siguiente\n");

		if(nArchivos >= 3)
			printf("6)Mostrar primero\n"
					"7)Mostrar Ultimo");

		printf("Seleccione opcion: ");

		scanf("%d", &menu);

		switch(menu){
		case 1:
			if(!stack_isEmpty(siguiente))
				lector_descargarDatos(siguiente, anterior, reciente);

			if(reciente)
				stack_push(anterior, reciente);

			reciente = leerArchivo();

			printArchivo(reciente);


			nArchivos++;
			break;

		case 3://Mostrar reciente
			printArchivo(reciente);
			break;

		case 4://Mostrar anterior
			if(stack_isEmpty(anterior))
				printf("No existe archivo anterior\n");

			else{
			stack_push(siguiente, reciente);
			reciente = stack_pop(anterior);
			printArchivo(reciente);
			}
			break;

		}



	}



	return 0;
}
