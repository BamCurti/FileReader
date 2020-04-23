/*
 * Type.h
 *
 *  Created on: Mar 26, 2020
 *      Author: administrador
 */

#ifndef TYPE_H_
#define TYPE_H_

typedef enum {FALSE, TRUE} boolean;
typedef void * Type;

Type Int(int);

Type Float(float);

Type Char(char);

Type String(char *);

#endif /* TYPE_H_ */
