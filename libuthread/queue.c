#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <queue.h>


struct queue {
	int size;
	struct queue* head;
	struct queue* tail;
	struct queue* prev;
	struct queue* next;
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
	// If the queue or data fails to give data, return error
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

	//If the enqueue is the first data
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
	if (queue == NULL || data == NULL) {
		return -1;
	}
	queue_t item;
	item = queue;

	while ((queue->size) > 0)
	{
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
	if (queue == NULL || func == NULL) {
		return -1;
	}
	int count = 0;
	queue_t item;
	item = queue;

	while ((item->size) != count)
	{
	func(item, item->data);
	item->prev = item;
	item = item->next;
	count++;
	}
	
}

int queue_length(queue_t queue)
{
	if (queue == NULL) {
		return -1;
	}
	else {
		return queue->size;
	}
}