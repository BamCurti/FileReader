/*
 * stack.h
 *
 *  Created on: 17 mar. 2020
 *      Author: Edgar Vallejo Curti
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "Type.h"

typedef void* Type;
typedef struct strStack* Stack;
typedef struct strNode* Node;


Stack stack_create();
boolean stack_isEmpty(Stack);
Type stack_top(Stack);
void stack_push(Stack, Type);
Type stack_pop(Stack);
void stack_destroy(Stack);
Node create_node(Type);
int stack_size(Stack);




#endif /* STACK_H_ */
