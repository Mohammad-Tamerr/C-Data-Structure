#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue_t *my_queue;
uint32 maxsize  ;
QueueStatus_t status ;
int main()
{
    uint32 element = 0 ;
    printf("please enter the size of queue \n");
    scanf("%d", &maxsize);
    my_queue = Create_Queue (maxsize , &status);
    printf("***********************\n");
    printf("plese enter the number \n");
    scanf("%d",&element);
    status = Enqueue(my_queue , &element);
    printf("the status is -> %d\n" ,status );
    printf("plese enter the number \n");
    scanf("%d",&element);
    status = Enqueue(my_queue , &element);
    printf("the status is -> %d\n" ,status );
    printf("plese enter the number \n");
    scanf("%d",&element);
    status = Enqueue(my_queue , &element);
    printf("the status is -> %d\n" ,status );
    printf("plese enter the number \n");
    scanf("%d",&element);
    status = Enqueue(my_queue , &element);
    printf("the status is -> %d\n" ,status );
    printf("plese enter the number \n");
    scanf("%d",&element);
    status = Enqueue(my_queue , &element);
    printf("the  status is ->%d\n" ,status );
    element = Dequeue(my_queue , &status);
    printf("element dequed -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    element = Dequeue(my_queue , &status);
    printf("element dequed -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    element = Dequeue(my_queue , &status);
    printf("element dequed -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    element = Dequeue(my_queue , &status);
    printf("element dequed -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    element = Queue_Front(my_queue ,&status);
    printf("element in front -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    element = Queue_Rear(my_queue ,&status);
    printf("element in Rear -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    printf("***********************\n");
    printf("***********************\n");
    element = Dequeue(my_queue , &status);
    printf("element dequed -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    element = Dequeue(my_queue , &status);
    printf("element dequed -> %d \n",element);
    printf("the  status is ->%d\n" ,status );
    printf("***********************\n");
    status = Destroy_Queue(my_queue);
    if(status == QUEUE_Destroyed)
    {
        printf("Queue Has Been Destroyed \n");
    }
    else
    {
        printf("Error !!!!! \n");
    }

    return 0;
}

