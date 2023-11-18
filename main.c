#include "queue.h"


int main(){
    int cap;
    struct myQueue *q=NULL;
    printf("Enter size of queue: ");
    scanf("%d", &cap);
    q = createQueue(cap);
    enQueue(q, 12);
    enQueue(q, 13);
    enQueue(q, 14);
    enQueue(q, 15);
    displayQueue(q);
    return 0;
}
