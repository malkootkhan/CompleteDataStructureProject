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



#include "deque.h"


int getUserData(){
     int d;
     printf("Enter data: ");
     scanf("%d",&d);
    return d;            
}

int main(){
    int choice,cap;
    struct deque_t *q=NULL;
    printf("Enter deque capacity: ");
    scanf("%d",&cap);
    q = createDeque(cap); //As it is dynamic queue so no need to specify capacity
    while (TRUE){
        printf("press '1' for insert rear data\n");
        printf("press '2' for insert front data\n");
        printf("press '3' for delete rear data\n");
        printf("press '4' for delete front data\n");
        printf("press '5' for get rear data\n");
        printf("press '6' for get front data\n");
        printf("press '7' for display data\n");
        printf("press '8' for release and exit the program\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case INSERT_R:
               insertRear(q,getUserData());
                break;
            case INSERT_F:
                insertFront(q, getUserData());
                break;
            case DEL_REAR:
                delRear(q);
                break;
            case DEL_FRONT:
                delFront(q);
                break;
            case GET_REAR:
                getRear(q);
                break;
            case GET_FRONT:
                getFront(q);
                break;
            case DISPLAY_DEQUE:
                displayDeque(q);
                break;
            case REL_EXIT:
                releaseMemExit(q);
                break;
            }
        }
    return 0;

}
