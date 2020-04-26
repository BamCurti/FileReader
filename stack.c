/*
 * stack.c
 *
 *  Created on: 17 mar. 2020
 *      Author: Edgar Vallejo Curti
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Type.h"

struct strNode{
	Type data;
	struct strNode *prior;
};
typedef struct strNode* Node;

struct strStack{
	Node top;
	int size;
};
typedef struct strStack* Stack;

//FUNCIONES
Stack stack_create(){
	Stack new = (Stack)malloc(sizeof(struct strStack));
	new->size = 0;
	new->top = NULL;

	return new;
}
boolean stack_isEmpty(Stack stack){
	if(stack){
		if(stack->top == NULL)	return FALSE;
	}
	return TRUE;
}

void stack_push(Stack s, Type d){
	if(s){
		//Si la pila existe
		//Agregar el dato a stack
		Node new = create_node(d);
		s->size+=1;

		if(s->top==NULL){

			s->top = new;
		}

		else
		{
			new->prior = s->top;
			s->top = new;
		}
	}
}
Node create_node(Type d){
	Node new = (Node)malloc(sizeof(struct strNode));
	new->data = d;
	new->prior = NULL;
	return new;
}
int stack_size(Stack s){
	if(s){
		return s->size;
	}

	return 0;
}
Type stack_top(Stack s){
	if(s)
		if(s->size != 0)
			return s->top->data;

	return NULL;

}
Type stack_pop(Stack s){
	Type dato = stack_top(s);
	if(dato){
		s->top = s->top->prior;
		s->size--;
	}

	return dato;
}
void stack_destroy(Stack s){
	if(s)
	{
		while(stack_size(s))
			stack_pop(s);

		free(s);
	}
}
