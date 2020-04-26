/*
 * Type.c
 *
 *  Created on: Mar 26, 2020
 *      Author: administrador
 */
#include <string.h>
#include <stdlib.h>
#include "Type.h"

Type Int(int n){
	int * new = NULL;
	while(new == NULL)
		new = (int *)malloc(sizeof(int));

	*new=n;
	return (Type)new;
}

Type Float(float f){
	float * new = NULL;
	while(new == NULL)
		new = (float *)malloc(sizeof(float));

	*new=f;
	return (Type)new;
}

Type Char(char c){
	char * new = NULL;
	while(new == NULL)
		new = (char *)malloc(sizeof(char));

	*new=c;
	return (Type)new;
}

Type String(char *s){
	char * new = NULL;
	while(new == NULL)
		new = strdup(s);
	return (Type)new;
}

int cmpInt(Type k1, Type k2){
	int a=*(int*)k1;
	int b=*(int*)k2;
	return a - b;
}

