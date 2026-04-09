#include <stdio.h>
#include <stdlib.h>
#include "priority_que.h"

struct pair
{
    int key;
    int value;
};
typedef struct pair Pair;

struct priority_queue
{
    int size;
    int capacity;
    Pair* data;
};
typedef struct priority_queue Priority_queue;


// extra functions
void print_queue(PRIORITY_QUEUE hQueue);
void fix_up(Pair* data, int index);
void fix_down(Pair* data, int index, int size);

void print_queue(PRIORITY_QUEUE hQueue)
{
    Priority_queue* pQueue = (Priority_queue*)hQueue;
    
    for(int n = 0; n < pQueue->size; ++n)
        printf("%d:%d\n", pQueue->data[n].key, pQueue->data[n].value);
}

void fix_up(Pair* data, int index)
{
	if (index > 0)
	{
		int index_of_parent = (index - 1) / 2;
		if (data[index].key > data[index_of_parent].key)
		{
			Pair temp;
			temp = data[index];
			data[index] = data[index_of_parent];
			data[index_of_parent] = temp;
			fix_up(data, index_of_parent);
		}
	}
}

void fix_down(Pair* data, int index, int size)
{
	int index_of_left_child = index * 2 + 1;
	int index_of_right_child = index * 2 + 2;
	int index_of_largest_child;

	if (index_of_left_child < size) //we have at least one child
	{
		if (index_of_right_child < size) //two children
		{
			index_of_largest_child = (data[index_of_left_child].key > data[index_of_right_child].key) ? index_of_left_child : index_of_right_child;
		}
		else if (index_of_left_child < size)
		{
			index_of_largest_child = index_of_left_child;
		}
		if (data[index_of_largest_child].key > data[index].key)
		{
			Pair temp;
			temp = data[index];
			data[index] = data[index_of_largest_child];
			data[index_of_largest_child] = temp;
			fix_down(data, index_of_largest_child, size);
		}
	}
}

PRIORITY_QUEUE priority_queue_init_default(void)
{
    Priority_queue* pPriority_queue = (Priority_queue*)malloc(sizeof(Priority_queue));
    if (pPriority_queue != NULL)
    {
        pPriority_queue->size = 0;
        pPriority_queue->capacity = 2;
        pPriority_queue->data = (Pair*)malloc(sizeof(Pair) * pPriority_queue->capacity);
        if (pPriority_queue->data == NULL)
        {
            printf("Failed to allocate space for priority queue\n");
            exit(1);
        }
    }
    
    return pPriority_queue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    Priority_queue* pQueue = (Priority_queue*)hQueue;
    
    
    if (pQueue->size >= pQueue->capacity)
    {
        
        Pair* temp = (Pair*)malloc(sizeof(Pair) * (pQueue->capacity * 2));
        
        if (temp == NULL)
        {
            printf("Failed to allocate space for priority queue\n");
            return FAILURE;
            exit(1);
        }
        
        for (int n = 0; n < pQueue->size; ++n)
            temp[n] = pQueue->data[n];
        
        free(pQueue->data);
        pQueue->data = temp;
        
        pQueue->capacity = pQueue->capacity * 2;
    }
    
    
    pQueue->data[pQueue->size].key = priority_level;
    pQueue->data[pQueue->size].value = data_item;

	pQueue->size++;
	fix_up(pQueue->data, pQueue->size - 1);
	
	return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    Priority_queue* pQueue = (Priority_queue*)hQueue;
    
    if (priority_queue_is_empty(pQueue) == TRUE)
    {
        printf("Can't service queue because there is nothing to service.\n");
        return FAILURE;
    }
    
    Pair temp;
	temp = pQueue->data[0];
	pQueue->data[0] = pQueue->data[pQueue->size - 1];
	pQueue->data[pQueue->size - 1] = temp;

	(pQueue->size)--;

	fix_down(pQueue->data, 0, pQueue->size);
	
	return SUCCESS;
}

//Precondition: hQueue is a handle to a valid priority queue opaque object.
//Postcondition: returns a copy of the data value for the
// highest priority item in the queue. Sets the variable at the address
// referred to in pStatus to SUCCESS if there is
// at least one item in the queue and FAILURE otherwise. If pStatus is
// passed in as NULL then the status value is ignored for this run of the
// function.
int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
    Priority_queue* pQueue = (Priority_queue*)hQueue;
    
    if(priority_queue_is_empty(pQueue))
    {
        if (pStatus != NULL)
            *pStatus = FAILURE;
        return -1;   
    }
    
    if (pStatus != NULL)
        *pStatus = SUCCESS;
    
    return pQueue->data[0].value;

}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Priority_queue* pQueue = (Priority_queue*)hQueue;
    
    return (pQueue->size <= 0) ? TRUE : FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Priority_queue* pQueue = (Priority_queue*)(*phQueue);

    free(pQueue->data);
    free(pQueue);
    *phQueue = NULL;
    
    printf("Priority queue destroyed!\n");
}
