/*
 * lector.h
 *
 *  Created on: 22 abr. 2020
 *      Author: Edgar Vallejo Curti
 */

#ifndef LECTOR_H_
#define LECTOR_H_
#include "deque.h"

typedef struct str_Archivo *Archivo;

//FUNCIONES LISTAS
char* leerString();
void readLine(char** , int *);
void reallocString(char** , int *);
Archivo leerArchivo();
void printArchivo(Archivo);
//FUNCIONES A PROGRAMAR

void printMenu(Deque);
void lector_leerArchivo(Deque);
void lector_mostrarReciente(Deque);
void lector_mostrarAnterior(Deque);
void lector_mostrarSiguiente(Deque);
void lector_mostrarPrimero(Deque);
void lector_mostrarUltimo(Deque);




#endif /* LECTOR_H_ */
