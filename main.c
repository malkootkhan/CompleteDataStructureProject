/*
file name: main.c
Author name: Malkoot Khan
description: simple implementation of queue data structure in c

License: 

Copyright (c) 2023 Malkoot Khan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
The Software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the Software.
 */



#include "queue.h"


int main(){
    int choice,d;
    struct myQueue *q=NULL;
    q = createQueue(); //As it is dynamic queue so no need to specify capacity
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
                releaseMemExit(q);

        }
    }
    return 0;

}
