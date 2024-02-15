#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

static uint8 QueueIsFull(Queue_t *queue_obj){
    return (queue_obj->ElementCount == queue_obj->QueueMaxSize);
}

static uint8 QueueIsEmpty(Queue_t *queue_obj){
    return (0 == queue_obj->ElementCount);
}

Queue_t *Create_Queue(uint32 maxsize , QueueStatus_t *queue_status)
{
    Queue_t *Queue = NULL ;
    if( (NULL == queue_status) )
    {
        *queue_status = QUEUE_NULL_POINTER ;
    }
    else
    {
        Queue = (Queue_t *)malloc (sizeof(Queue_t));
        if(NULL==Queue)
        {
            *queue_status = QUEUE_NOK ;
        }
        else
        {
            Queue->ElementCount = 0 ;
            Queue->QueueFront = -1 ;
            Queue->QueueRear = -1 ;
            Queue->QueueMaxSize = maxsize ;
            Queue->QueueArray = (uint32 *) calloc (maxsize , sizeof(uint32)) ;
            if(NULL == Queue->QueueArray )
            {
                *queue_status = QUEUE_NOK ;
                Queue = NULL ;
            }
            else
            {
                *queue_status = QUEUE_OK ;
                printf("Queue Has Been Created \n");
            }
        }
    }
        return Queue ;
}

QueueStatus_t Enqueue(Queue_t *Queue_obj ,uint32 *element)
{
    QueueStatus_t status = QUEUE_NOK ;
    if((NULL == Queue_obj) || (NULL == element) )
    {
        status = QUEUE_NULL_POINTER ;
    }
    else
    {
        if(QueueIsFull(Queue_obj))
        {
            status = QUEUE_FULL ;
        }
        else
        {
            (Queue_obj->QueueRear)++ ;
            if(Queue_obj->QueueRear == Queue_obj->QueueMaxSize)
            {
                (Queue_obj->QueueRear) = 0 ;
            }
            else{/* nothing */}
            if ( Queue_obj->ElementCount == 0 )
            {
                Queue_obj->QueueFront = 0;
                Queue_obj->ElementCount = 1;
            }
            else
            {
                (Queue_obj->ElementCount)++ ;
            }
            Queue_obj->QueueArray[Queue_obj->QueueRear] = *element ;
            status = QUEUE_OK;
        }

    }
    return status ;
}

uint32 Dequeue(Queue_t *Queue_obj ,QueueStatus_t * queue_status)
{
    uint32 ret_element = 0 ;
     if((NULL == Queue_obj) || (NULL == queue_status) )
    {
        *queue_status = QUEUE_NULL_POINTER ;
    }
    else
    {
        if(QueueIsEmpty(Queue_obj))
        {
            *queue_status = QUEUE_EMPTY ;
        }
        else
        {
            ret_element = Queue_obj->QueueArray[Queue_obj->QueueFront];
            (Queue_obj->QueueFront)++ ;
            if(Queue_obj->QueueFront == Queue_obj->QueueMaxSize )
            {
                Queue_obj->QueueFront = 0 ;
            }
            else{}
            if(Queue_obj->ElementCount == 1)
            {
                Queue_obj->QueueFront = -1 ;
                Queue_obj->QueueRear = -1 ;
            }
            else {}
            (Queue_obj->ElementCount)-- ;
            *queue_status = QUEUE_OK ;
        }
        return ret_element;
}
}


uint32 Queue_Front(Queue_t *Queue_obj ,QueueStatus_t * queue_status)
{
     uint32 ret_element = 0 ;
     if((NULL == Queue_obj) || (NULL == queue_status) )
    {
        *queue_status = QUEUE_NULL_POINTER ;
    }
    else
    {
        if(QueueIsEmpty(Queue_obj))
        {
            *queue_status = QUEUE_EMPTY ;
        }
        else
        {
            ret_element = Queue_obj->QueueArray[Queue_obj->QueueFront] ;
            *queue_status = QUEUE_OK ;
        }

    }
    return ret_element ;
}

uint32 Queue_Rear(Queue_t *Queue_obj ,QueueStatus_t * queue_status)
{

uint32 ret_element = 0 ;
     if((NULL == Queue_obj) || (NULL == queue_status) )
    {
        *queue_status = QUEUE_NULL_POINTER ;
    }
    else
    {
        if(QueueIsEmpty(Queue_obj))
        {
            *queue_status = QUEUE_EMPTY ;
        }
        else
        {
            ret_element = Queue_obj->QueueArray[Queue_obj->QueueRear] ;
            *queue_status = QUEUE_OK ;
        }

    }
    return ret_element ;
}

uint32 Queue_Count(Queue_t *Queue_obj ,QueueStatus_t * queue_status)
{
    uint32 ret_element = 0 ;
     if((NULL == Queue_obj) || (NULL == queue_status) )
    {
        *queue_status = QUEUE_NULL_POINTER ;
    }
    else
    {
        if(QueueIsEmpty(Queue_obj))
        {
            Queue_obj->ElementCount = 0 ;
        }
        else
        {
            ret_element = Queue_obj->ElementCount ;
        }
            *queue_status = QUEUE_OK ;
    }

    return ret_element ;
}


QueueStatus_t Destroy_Queue(Queue_t *Queue_obj)
{
    QueueStatus_t ret_status = QUEUE_NOK ;
    if(NULL == Queue_obj)
    {
        ret_status = QUEUE_NULL_POINTER ;
    }
    else
    {
        free(Queue_obj->QueueArray) ;
        free(Queue_obj) ;
        ret_status = QUEUE_Destroyed ;
    }
    return ret_status;
}
