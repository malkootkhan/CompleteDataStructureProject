/*
file name: queue.h
Author name: Malkoot Khan
description: simple implementation of queue data structure in c

License: 

Copyright (c) 2023 Malkoot Khan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
The Software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the Software.
 */


#ifndef __QUEUE__
#define __QUEUE__

#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE,TRUE}bool;

struct list{
    int data;
    struct list *next;
};

struct myQueue{
    struct list *front;
    struct list *rear;
};

/*
 createQueue/initQueue
 enQueue
 deQueue
 displayQueue
 getFront
 getRear

 isEmpty
 isFull

 */
struct myQueue *createQueue();
void enQueue(struct myQueue *q, int data);
void deQueue(struct myQueue *q);
void displayQueue(struct myQueue *q);
int getFront(struct myQueue *q);
int getRear(struct myQueue *q);

/*Lower layer functions*/
bool isEmpty(struct myQueue *q);
bool isFull(struct myQueue *q);
#endif
