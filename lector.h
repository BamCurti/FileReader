/*
 * lector.h
 *
 *  Created on: 22 abr. 2020
 *      Author: Edgar Vallejo Curti
 */

#ifndef LECTOR_H_
#define LECTOR_H_

#include "stack.h"
#include "type.h"

typedef struct str_Archivo *Archivo;

//FUNCIONES LISTAS
char* leerString();
void readLine(char** , int *);
void reallocString(char** , int *);
Archivo leerArchivo();
void printArchivo(Archivo);
//FUNCIONES A PROGRAMAR

void lector_leerArchivo(Stack);
void lector_mostrarReciente(Stack);
void lector_mostrarAnterior(Stack);
void lector_mostrarSiguiente(Stack);
void lector_mostrarPrimero(Stack);
void lector_mostrarUltimo(Stack);
void lector_descargarDatos(Stack, Stack, Archivo);




#endif /* LECTOR_H_ */
