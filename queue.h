#ifndef __QUEUE__
#define __QUEUE__

#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE,TRUE}bool;

struct myQueue{
    int capacity;
    int front;
    int rear;
    int *data;
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
struct myQueue *createQueue(int cap);
void enQueue(struct myQueue *q, int data);
void deQueue(struct myQueue *q);
void displayQueue(struct myQueue *q);
int getFront(struct myQueue *q);
int getRear(struct myQueue *q);

/*Lower layer functions*/
bool isEmpty(struct myQueue *q);
bool isFull(struct myQueue *q);
#endif
