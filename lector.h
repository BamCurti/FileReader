/*
 * lector.h
 *
 *  Created on: 22 abr. 2020
 *      Author: Edgar Vallejo Curti
 */

#ifndef LECTOR_H_
#define LECTOR_H_

typedef struct str_archivo Archivo;
typedef struct str_lector Lector;

Lector crearLector();
char* leerString();
Archivo leerArchivo();
void printArchivo(Archivo);
void printMenu(Lector);
void lector_leerArchivo(Lector);
void lector_mostrarReciente(Lector);
void lector_mostrarAnterior(Lector);
void lector_mostrarSiguiente(Lector);
void lector_mostrarPrimero(Lector);
void lector_mostrarUltimo(Lector);

#endif /* LECTOR_H_ */
