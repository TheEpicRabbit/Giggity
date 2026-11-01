#include <iostream>
#include "Queue.h"

void initQueue(Queue* q, unsigned int size)
{
	q->_count = 0;
	q->_maxSize = size;

	q->_elements = (int*)calloc(q->_maxSize, sizeof(int));
	for (int i = 0; i < q->_maxSize; i++)
	{
		q->_elements[i] = -1;
	}
}

void cleanQueue(Queue* q)
{
	q->_count = 0;
	free(q->_elements);
	std::fill(q->_elements, q->_elements + q->_maxSize, -1);
}

void enqueue(Queue* q, unsigned int newValue)
{
	if (q->_count >= q->_maxSize)
	{
		return;
	}

	for (int i = 0; i < q->_maxSize; i++)
	{
		if (q->_elements[i] != -1)
		{
			q->_elements[i] = newValue;
			q->_count += 1;
			break;
		}
	}
}

int dequeue(Queue* q)
{
	if (q->_count == 0)
	{
		return -1;
	}

	int num = q->_elements[0];

	for (int i = 1; i < q->_maxSize; i++)
	{
		q->_elements[i - 1] = q->_elements[i];
	}

	q->_count -= 1;
	return num;
}

bool isEmpty(Queue* s)
{
	return (s->_count == 0);
}

bool isFull(Queue* s)
{
	return (s->_count == s->_maxSize);
}