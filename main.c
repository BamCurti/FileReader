/*
 * main.c
 *
 *  Created on: 25 abr. 2020
 *      Author: Edgar Vallejo Curti
 */

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "deque.h"
#include "lector.h"

int main(){
	setbuf(stdout, NULL);
	int menu = 0;
	Deque principal = deque_createDeque();
	Deque aux = deque_createDeque();

	Archivo reciente = NULL;
	Archivo anterior = NULL;
	Archivo siguiente = NULL;
	int nArchivos = 0;

	while(menu != 2){
		printf("1)Abrir Archivo\n"
				"2)Salir\n");
		if(nArchivos >= 1)
			printf("3)Mostrar reciente\n"
					"4)Mostrar Anterior\n"
					"5)Mostrar siguiente\n");

		if(nArchivos >= 3)
			printf("6)Mostrar primero"
					"7)Mostrar Ultimo");

		scanf("%d", &menu);

		switch(menu){
		case 1:
			if(anterior)
				deque_addFront(principal, anterior);

			if(reciente)
				anterior = reciente;

			reciente = leerArchivo();

			printArchivo(reciente);


			nArchivos++;
			break;


		}



	}



	return 0;
}
