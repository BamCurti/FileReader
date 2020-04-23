/*
 * deque.c
 *
 *  Created on: 14 abr. 2020
 *      Author: Edgar Vallejo Curti
 */


#include "deque.h"

struct strNode{
	struct strNode* next;
	struct strNode* prior;
	Type data;
};
struct strDeque{
	struct strNode* front;
	struct strNode* rear;
	unsigned int size;
};

Deque deque_createDeque(){
	Deque new = NULL;

	while(new == NULL)
		new = (Deque)malloc(sizeof(struct strDeque));

	new->front = NULL;
	new->rear = NULL;
	new->size = 0;

	return new;
}
void deque_addFront(Deque d, Type info){
	if(d){ //si deque existe
		Node new = createNode(info);

		if(deque_size(d)){ //Si el deque tiene elementos
			new->next = d->front; //El siguiente del nuevo dato será el front
			d->front->prior = new;//El anterior del front será el nuevo dato
		}

		else //Si está vacio
			d->rear = new; //El inicio y final será el nuevo dato

		d->front = new; //Ahora si, ponemos el dato al inicio

		d->size++;
	}
}
void deque_addRear(Deque d, Type info){
	if(d){ //si deque existe
		Node new = createNode(info);

		if(deque_size(d)){ //Si el deque tiene elementos
			new->prior = d->rear; //El dato que va antes del nuevo, es el que estaba
			d->rear->next = new;//El siguiente valor del final, es el nuevo
		}

		else //Si está vacio
			d->front = new; //El inicio y final será el mismo

		d->rear = new; //Ahora si, ponemos el dato al inicio

		d->size++;
	}
}
int deque_size(Deque d){
	if(d)
		return d->size;
	return -1;
}
boolean deque_isEmpty(Deque d){
	if(d)//Si existe
		if(d->size)//Si tiene elementos
			return FALSE;

	return TRUE;
}
Type deque_removeRear(Deque d){
	Type data = NULL;
	Node temp = NULL;

	if(d)//Si existe Deque
		if(deque_size(d)){//Si tiene datos
			temp = d->rear;
			data = d->rear->data;

			if(deque_size(d) > 1){
				d->rear->prior->next = NULL; //Desvinculo el next del anterior del rear
				d->rear = d->rear->prior;	//Digo que mi nuevo rear, es el anterior al rear
			}

			else{
				d->front = NULL;
				d->rear = NULL;
			}

			free(temp);
			d->size--;
		}

	return data;
}
Type deque_removeFront(Deque d){
	Type data = NULL;
	Node temp = NULL;

	if(d)//Si existe Deque
		if(deque_size(d)){//Si tiene datos
			temp = d->front;
			data = d->front->data;

			if(deque_size(d) > 1){
				d->front->next->prior = NULL; //Desvinculo el next del anterior del rear
				d->front = d->front->next;	//Digo que mi nuevo rear, es el anterior al rear
			}

			else{
				d->rear = NULL;
				d->front = NULL;
			}

			free(temp);
			d->size--;
		}

	return data;
}
void deque_destroyDeque(Deque d){
	if(d){
		while(!deque_isEmpty(d))
			deque_removeFront(d);

		free(d);
	}
}
Node createNode(Type info){
	Node new = NULL;
	while(new == NULL)
		new = (Node)malloc(sizeof(struct strNode));

	new->data = info;
	new->next = NULL;
	new->prior = NULL;

	return new;
}
