#include "queue.h"

bool isEmpty(struct myQueue *q){
    if(q->front==-1 && q->rear == -1)
        return TRUE;
    return FALSE;
}

bool isFull(struct myQueue *q){
    if(q->rear == q->capacity - 1 && q->front == 0)
        return TRUE;
    if(q->front == q->rear+1)
        return TRUE;
    return FALSE;
}

struct myQueue *createQueue(int cap){
    struct myQueue *q = (struct myQueue *)malloc(sizeof(struct myQueue));
    q->capacity = cap;
    q->front = -1;
    q->rear = -1;
    q->data = (int *)malloc(sizeof(int));
    return q;
}
void enQueue(struct myQueue *q, int data){

    if(isFull(q)){
        printf("The queue is full!\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
        q->data[q->rear] = data;
        return;
    }
    if(q->rear == q->capacity-1 && q->front != 0){
        q->rear = 0;
        q->data[q->rear] = data;
        return;
    }
    if(q->rear+1 != q->front){
        q->rear++;
        q->data[q->rear] = data;
        return;
    }
    
    printf("The queue is full!\n");

}
void deQueue(struct myQueue *q){
    if(isEmpty(q)){
        printf("The queue is empty!\n");
        return;
    }
    if(q->rear == q->front){
        q->front = -1;
        q->rear = -1;
        return;
    }
    if(q->front == q->capacity-1){
        q->front = 0;
        return;
    }
    
    q->front++;
}

void displayQueue(struct myQueue *q){
    if(isEmpty(q)){
        printf("The queue is empty!\n");
        return;
    }
    if(q->rear == q->front){
        printf("%d ", q->data[q->front]);
        return;
    }
    for(int i=q->front; i != q->rear; i++){
         if(i == q->capacity)
            i=0;
    
        printf("%d ", q->data[i]);
    
    }
    printf("%d \n", q->data[q->rear]);
}
int getFront(struct myQueue *q){
    if(isEmpty(q)){
        printf("The queue is empty!\n");
        return 0;
    }
    return q->data[q->front];
}
int getRear(struct myQueue *q){
    if(isEmpty(q)){
        printf("The queue is empty!\n");
        return 0;
    }
    return q->data[q->rear];
}
