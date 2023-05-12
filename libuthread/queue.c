#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "queue.h"

/* ----- Citation ----- */
/* The FIFO Queue implementation below was created by us partly by using 
a queue implementation originally made from another university 
as reference. We came up with ideas around this code and have 
manifested our own version although some parts might look similar. 

Credits for the reference: 
https://web.cs.dal.ca/~jamie/CS3171/Materials/KR_1e/Code/Chapter3/src/queue.c */

struct queue {
	int size;
	queue_t head, tail, prev, next; 
	void* data;
};

queue_t queue_create(void)
{
	queue_t queue;

	if (NULL != (queue = malloc(sizeof(struct queue)))) {
		if (&queue == NULL) {
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
	/* checks if queue is created and checks if there are contents in the queue to be destroyed */
	if (queue == NULL || queue->size != 0) {
		return -1;
	}

	else {
		while (!(!queue->size)) {
			free(queue->head->data);
			queue_dequeue(queue, &(queue->data));
		}

		return 0;
	}
}

int queue_enqueue(queue_t queue, void* data)
{
	/* If the queue or data fails to give data, return error */
	if (queue == NULL || data == NULL) {
		return -1;
	}

	queue_t Newqueue;
	Newqueue = malloc(sizeof(struct queue));

	if (Newqueue == NULL) {
		return -1;
	}

	Newqueue->data = data;
	Newqueue->next = NULL;

	/* If the enqueue is the first data */ 
	if (queue->size == 0) {
		queue->head = Newqueue;
		queue->tail = Newqueue;
		Newqueue->prev = NULL;
		Newqueue->next = NULL;
	}

	else {
		queue->tail->next = Newqueue;
		Newqueue->prev = queue->tail;
		Newqueue->next = NULL;
		queue->tail = Newqueue;
	}

	++queue->size;

	return 0;
}

int queue_dequeue(queue_t queue, void** data)
{
	if (queue == NULL || data == NULL || queue->size <= 0) {
		return -1;
	}

	queue_t item;

	if (queue->size > 0) {
		item = queue->head;
		data = &(queue->head->data);
		queue->head = item->next;

		if (queue->head) {
			queue->head->prev = NULL;
		}

		else {
			queue->tail = NULL;
		}

		--queue->size;
		free(item);
	}

	return 0;
}

int queue_delete(queue_t queue, void* data)
{
	/* Checks if Queue created and if there is any contents in the node */
	if (queue == NULL || data == NULL) {
		return -1;
	}

	queue_t item;
	item = queue;

	while ((queue->size) > 0) {
		if (data == item->data) {
			item->prev->next = item->next;
			item->next = NULL;
			item->prev = NULL;
			free(item);
			return 0;
		}
		
		item->prev = item;
		item = item->next;
		--queue->size;
	}

	return -1;
}

int queue_iterate(queue_t queue, queue_func_t func)
{
	/* Checks if Queue is created and if Function is empty */
	if (queue == NULL || func == NULL) {
		return -1;
	}

	int count = 0;
	queue_t item;
	item = queue;

	while ((item->size) != count) {
		func(item, item->data);
		item->prev = item;
		item = item->next;
		count++;
	}
}

int queue_length(queue_t queue)
{
	/* Checks if Queue is created */
	if (queue == NULL) {
		return -1;
	}

	else {
		return queue->size;
	}
}
