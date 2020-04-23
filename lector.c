/*
 * lector.c
 *
 *  Created on: 22 abr. 2020
 *      Author: Edgar Vallejo Curti
 */
#include "lector.h"
#include "Type.h"
#include "deque.h"

struct str_archivo{
	char* contenido;
	struct str_archivo* anterior;
	struct str_archivo* siguiente;
};

typedef struct str_archivo Archivo;

struct str_lector{
	Deque esqueleto;
	struct str_archivo* reciente;
};

typedef struct str_lector Lector;

