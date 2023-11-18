#include "queue.h"


int main(){
    int cap, choice,d;
    struct myQueue *q=NULL;
    printf("Enter size of queue: ");
    scanf("%d", &cap);
    q = createQueue(cap);
    while (TRUE){
        printf("press '1' for enqueue/insert data\n");
        printf("press '2' for dequeue/delete data\n");
        printf("press '3' for display data\n");
        printf("press '4' for exit the program\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&d);
                enQueue(q,d);
                break;
            case 2:
                deQueue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                exit(0);

        }
    }
    return 0;

}
