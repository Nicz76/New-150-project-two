#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

struct queue {
	int size;
	struct queue *head;
	struct queue *tail;
	struct queue *prev;
	struct queue *next;
	void * data;

};

queue_t queue_create(void)
{
	queue_t queue;
	if (NULL != (queue = malloc(sizeof(struct queue)))){
		if (queue == NULL){
		return NULL;
		}
		queue->size = 0;
		queue->head = NULL;
		queue->tail = NULL;
	}
		return queue;
}

int queue_destroy(queue_t queue)
{
	if (queue == NULL || !queue->size != 0){
		return -1;
	}
	
	else{
		while (!queue_empty(queue)){
			free(queue_top(queue));
			queue_dequeue(queue);
		}
	return 0;
	}
}

int queue_enqueue(queue_t queue, void *data)
{
	// If the queue or data fails to give data, return error
	if (queue == NULL || data == NULL){
		return -1;
	}

	queue_t Newqueue;
	Newqueue = malloc(sizeof(struct qitem));

	if (Newqueue == NULL){
	 	return -1;
	}

	Newqueue->data = data;
	Newqueue->next = NULL;

	//If the enqueue is the first data
	if (queue_empty(queue)){
		queue->head = Newqueue;
		queue->tail = Newqueue;
		Newqueue->prev = NULL;
		Newqueue->next = NULL;
	}
	else{
		queue->tail->next = Newqueue;
		Newqueue->prev = queue->tail;
		Newqueue->next = NULL;
		queue->tail = Newqueue;
	}
	++queue->size;

	return 0;
}

int queue_dequeue(queue_t queue, void **data)
{
	if (queue == NULL || data == NULL || queue_empty(queue)){
		return -1;
	}

	queue_t item;

	if (!queue_empty(queue)){
		item = queue->head;
		data = queue->head->data;
		queue->head = item->next;

		if (queue->head){
			queue->head->prev = NULL;
		}
		else{
			queue->tail = NULL;
		}
		--queue->size;
		free(item);
	}
}

int queue_delete(queue_t queue, void *data)
{
	if (queue == NULL || data==NULL || queue_empty(queue)){
		return -1;
	}
		queue_t item;

	while (!queue_empty(queue))
	{
		if (data == queue->)
	}
	/* TODO Phase 1 */
	/*
 * queue_delete - Delete data item
 * @queue: Queue in which to delete item
 * @data: Data to delete
 *
 * Find in queue @queue, the first (ie oldest) item equal to @data and delete
 * this item.
 *
 * Return: -1 if @queue or @data are NULL, of if @data was not found in the
 * queue. 0 if @data was found and deleted from @queue.
 */

}

int queue_iterate(queue_t queue, queue_func_t func)
{
	/* Callback function that increments items */
static void iterator_inc(queue_t q, void *data)
{
    int *a = (int*)data;

    if (*a == 42)
        queue_delete(q, data);
    else
        *a += 1;
}

void test_iterator(void)
{
    queue_t q;
    int data[] = {1, 2, 3, 4, 5, 42, 6, 7, 8, 9};
    size_t i;

    /* Initialize the queue and enqueue items */
    q = queue_create();
    for (i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        queue_enqueue(q, &data[i]);

    /* Increment every item of the queue, delete item '42' */
    queue_iterate(q, iterator_inc);
    assert(data[0] == 2);
    assert(queue_length(q) == 9);
}
	/* TODO Phase 1 */
/*
 * queue_iterate - Iterate through a queue
 * @queue: Queue to iterate through
 * @func: Function to call on each queue item
 *
 * This function iterates through the items in the queue @queue, from the oldest
 * item to the newest item, and calls the given callback function @func on each
 * item. The callback function receives the current data item as parameter.
 *
 * Note that this function should be resistant to data items being deleted
 * as part of the iteration (ie in @func).
 *
 * Return: -1 if @queue or @func are NULL, 0 otherwise.
 */
}

int queue_length(queue_t queue)
{
	if (queue == NULL){
		return -1;
	}
	else{
		return !queue->size;
	}
}

