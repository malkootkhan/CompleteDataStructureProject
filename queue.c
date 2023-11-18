/*
file name: queue.c
Author name: Malkoot Khan
description: simple implementation of queue data structure in c using linked list/dynamic allocation

License: 

Copyright (c) 2023 Malkoot Khan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
The Software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the Software.
 */

#include "queue.h"

struct myQueue *createQueue(){
    struct myQueue *q = (struct myQueue *)malloc(sizeof(struct myQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
struct list *createNode(int data){
    struct list *temp = (struct list *)malloc(sizeof(struct list));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void enQueue(struct myQueue *q , int data){
    struct list *newNode = createNode(data);
    if(q->front == NULL && q->rear == NULL){
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

void deQueue(struct myQueue *q){
    if(q->front==NULL && q->rear==NULL){
        printf("The queue is empty!\n");
        return;
    }
    struct list *temp = q->front;
    q->front = q->front->next;
    free(temp);
}

void displayQueue(struct myQueue *q){
    if(q->front == NULL && q->rear == NULL){
        printf("The queue is empty!\n");
        return;
    }
    struct list *tmp = q->front;
    while(tmp != q->rear){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("%d \n", tmp->data);
}

int getFront(struct myQueue *q){
    if(q->front == NULL){
        printf("The queue is empty!\n");
        return 0;
    }
    return q->front->data;
}

int getRear(struct myQueue *q){
    if(q->rear == NULL){
        printf("The queue is empty!\n");
        return 0;
    }
    return q->rear->data;
}
