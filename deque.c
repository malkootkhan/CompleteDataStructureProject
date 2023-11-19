/*
file name: deque.c
Author name: Malkoot Khan
description: simple implementation of deque data structure in c


Copyright (c) 2023 Malkoot Khan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
The Software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the Software.
 */

#include "deque.h"

bool isEmpty(struct deque_t *dq){
    if(dq->front == -1 && dq->rear == -1)
        return TRUE;
    return FALSE;

}
bool isFull(struct deque_t *dq){
    if(dq->front == 0 && dq->rear == dq->capacity - 1)
        return TRUE;
    return FALSE;
}

struct deque_t *createDeque(int cap){
    struct deque_t *dq = (struct deque_t *)malloc(sizeof(struct deque_t));
    dq->capacity = cap;
    dq->front = -1;
    dq->rear = -1;
    dq->data = (int *)malloc(cap*sizeof(int));
    return dq;
}
void insertRear(struct deque_t *dq , int data){
    if(isFull(dq)){
        printf("deque is full!\n");
        return;
    }
    if(isEmpty(dq)){
        dq->rear = 0;
        dq->front = 0;
        dq->data[dq->rear] = data;
        return;
    }
    dq->rear++;
    if(dq->rear == dq->capacity && dq->front != 0)
        dq->rear = 0;
    if(dq->rear != dq->front){
        dq->data[dq->rear] = data;
        return;    
    }
    dq->rear--;
    printf("The deque is full!\n");
}
void insertFront(struct deque_t *dq, int data){
    if(isFull(dq)){
        printf("The deque is full!\n");
        return;
    }
    if(isEmpty(dq)){
        dq->front = 0;
        dq->rear = 0;
        dq->data[dq->front] = data;
        return;
    }

    dq->front--;
    if(dq->front == -1)
        dq->front = dq->capacity -1;
    if(dq->front == dq->rear){
        printf("The deque is full!\n");
        dq->front++;
        return;
    }
    dq->data[dq->front] = data;      
}
void delRear(struct deque_t *dq){
    if(isEmpty(dq)){
        printf("The deque is empty!\n");
        return;
    }
    
    if(dq->front == dq->rear){
        dq->front = -1;
        dq->rear = -1;
        return;
    }
    dq->rear--;
    if(dq->rear == -1)
        dq->rear = dq->capacity - 1;
  
}
void delFront(struct deque_t *dq){
    if(isEmpty(dq)){
        printf("The deque is empty!\n");
        return;
    }
    if(dq->front == dq->rear){
        dq->front = -1;
        dq->rear = -1;
        return;
    }
    dq->front++;
    if(dq->front == dq->capacity)
        dq->front = 0;

}
    
void displayDeque(struct deque_t *dq){
    if(isEmpty(dq)){
        printf("The deque is empty!\n");
        return;
    }
    /*If there is single element in the deque*/
    if(dq->front == dq->rear){
        printf("%d \n", dq->data[dq->front]);
        return;
    }
    int i =dq->front;
    while(i != dq->rear){
        printf("%d ",dq->data[i]);
        i++;
        if(i == dq->capacity)
            i =0;
    }
    printf("%d \n", dq->data[dq->rear]);
}

void getFront(struct deque_t *dq){
    if(isEmpty(dq)){
        printf("The queue is empty!\n");
        return ;
    }
    printf("%d \n", dq->data[dq->front]);
}

void getRear(struct deque_t *dq){
    if(isEmpty(dq)){
        printf("The queue is empty!\n");
        return;
    }
    printf("%d \n", dq->data[dq->rear]);
}
/*It is highly recommended to release the dynamically allocated memory before closing the program*/
void releaseMemExit(struct deque_t *dq){
    free(dq->data);
    free(dq);
    exit(0);
}

