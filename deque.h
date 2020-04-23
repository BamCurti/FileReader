/*
 * deque.h
 *
 *  Created on: 14 abr. 2020
 *      Author: Edgar Vallejo Curti
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "Type.h"

//DEFINICIONES
typedef struct strNode* Node;
typedef struct strDeque* Deque;

//FUNCIONES
Deque deque_createDeque();
void deque_addFront(Deque, Type);
void deque_addRear(Deque, Type);
int deque_size(Deque);
boolean deque_isEmpty(Deque);
Type deque_removeRear(Deque);
Type deque_removeFront(Deque);
void deque_destroyDeque(Deque);
Node createNode(Type);

#endif /* DEQUE_H_ */
