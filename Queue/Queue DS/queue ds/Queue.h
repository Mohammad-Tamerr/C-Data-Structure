#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
typedef struct {

    uint32 *QueueArray;   /* Pointer to array of uint32 elemnts */
    uint32 QueueMaxSize; /* Maximum elements in the Queue */
    uint32 ElementCount; /* Number of elements in the Queue */
    sint32 QueueFront;   /* Index of the front element */
    sint32 QueueRear;    /*  Index  of  the  rear element */

}Queue_t ;

typedef enum{
    QUEUE_NOK = 0,     /* Queue operation not performed successfully */
    QUEUE_OK,          /* Queue operation performed successfully  */
    QUEUE_FULL,        /* Queue is full */
    QUEUE_EMPTY,       /* Queue is empty */
    QUEUE_NULL_POINTER, /* NULL pointer passed to the Queue */
    QUEUE_Destroyed

}QueueStatus_t;


Queue_t *Create_Queue(uint32 maxsize , QueueStatus_t *queue_status);
QueueStatus_t Enqueue(Queue_t *Queue_obj ,uint32 *element);
uint32 Dequeue(Queue_t *Queue_obj ,QueueStatus_t * queue_status);
uint32 Queue_Front(Queue_t *Queue_obj ,QueueStatus_t * queue_status);
uint32 Queue_Rear(Queue_t *Queue_obj ,QueueStatus_t * queue_status);
uint32 Queue_Count(Queue_t *Queue_obj ,QueueStatus_t * queue_status);
QueueStatus_t Destroy_Queue(Queue_t *Queue_obj);

#endif // _QUEUE_H
