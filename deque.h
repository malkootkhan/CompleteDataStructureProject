/*
file name: deque.h
Author name: Malkoot Khan
description: simple implementation of deque data structure in c


Copyright (c) 2023 Malkoot Khan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
The Software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the Software.
 */


#ifndef __DEQUE__
#define __DEQUE__

#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE,TRUE}bool;
typedef enum {INSERT_R=1, INSERT_F,DEL_REAR,DEL_FRONT,GET_REAR,GET_FRONT,DISPLAY_DEQUE,REL_EXIT}operation_t;

struct deque_t{
    int capacity;
    int front;
    int rear;
    int *data;
};

struct deque_t *createDeque(int cap);
void insertRear(struct deque_t *dq, int data);
void insertFront(struct deque_t *dq, int data);
void delRear(struct deque_t *dq);
void delFront(struct deque_t *dq);
void displayDeque(struct deque_t *dq);
void getFront(struct deque_t *dq);
void getRear(struct deque_t *dq);
void releaseMemExit(struct deque_t *dq);

/*Lower layer functions*/
bool isEmpty(struct deque_t *dq);
bool isFull(struct deque_t *dq);
#endif
