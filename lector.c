/*
 * lector.c
 *
 *  Created on: 22 abr. 2020
 *      Author: Edgar Vallejo Curti
 */
#include "lector.h"
#include "Type.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str_Archivo{
	char* info;
	char *titulo;
};


//FUNCIONES
char* leerString(){

	char *texto = NULL;
	int largo = 0;

	reallocString(&texto, &largo);
	readLine(&texto, &largo);

	return texto;

	return NULL;
}
void readLine(char** lst, int *largo){
    int c;
    int pos = 0;
    fflush(stdin);

    c = getchar();
    while (c != '\n' && c != EOF) {
		reallocString(lst, largo);
        (*lst)[pos] =(char) c;
        pos++;
        c = getchar();
    }
    (*lst)[pos] = '\0';
}
void reallocString(char** lst, int *largo){
    (*largo) += 1;
    char* temp = NULL;
    while(temp == NULL){
    	temp = (char*) realloc(*lst, (*largo) * sizeof (char));
    }
    *lst = temp;
}
Archivo leerArchivo(){
	Archivo new = NULL;
	char* direccion;

	while(new == NULL)
		new = (Archivo)malloc(sizeof(struct str_Archivo));

	printf("Nombre del archivo: ");
	direccion = leerString();
	new->titulo = direccion;
	FILE *archivo = fopen((char*)direccion, "r");

    fseek(archivo, 0, SEEK_END);	/* file pointer at the end of file */
	long nbytes = ftell(archivo);	// Numero de caracters hasta el final
	rewind(archivo); //Volver al inicio de la función
	new->info =  (char*)malloc(nbytes * sizeof(char));

	char c;
	int i;
	for(i = 0; (c = fgetc(archivo)) != EOF && i < nbytes; i++)
		new->info[i] = c;


	new->info[i] = '\0';
	fclose(archivo);

	return new;
}
void printArchivo(Archivo a){
	printf("Archivo: %s\n", a->titulo);
	printf("%s\n", a->info);
	printf("\n");
}
void lector_descargarDatos(Stack *origen, Stack *destino, Archivo *medio){
	while(stack_size(*origen)){
		stack_push(*destino, *medio);
		*medio = stack_pop(*origen);
	}
}
boolean lector_isTheSame(Archivo a, Archivo b){
	boolean status = FALSE;
	if(a == NULL || b == NULL)
		return FALSE;

	int r = strcmp(a->info,b->info);
	if(r == 0) status = TRUE;

	return status;
}
