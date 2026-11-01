#include <iostream>
#include "Stack.h"

void push(Stack* s, unsigned int element)
{
	if (isFull(s) != true)
	{
		Node* node = new Node();
		node->value = element;
		s->_count += 1;

		s->head = addNode(s->head, node);
	}
}

int pop(Stack* s)
{
	int num = s->head->value;

	Node* node = removeNode(s->head);
	s->head = node;

	s->_count -= 1;

	return num;
}

void initStack(Stack* s,int _maxSize)
{
	s->head = nullptr;
	s->_maxSize = _maxSize;
	s->_count = 0;
}

void cleanStack(Stack* s)
{
	if (s->head != nullptr)
	{
		Node* head = s->head;

		while (true)
		{
			Node* curr = head;
			head = head->next;
			delete curr;

			if (head == nullptr)
			{
				break;
			}
		}

		s->head = nullptr;
		s->_count = 0;
	}
	s->_count = 0;
}

bool isEmpty(Stack* s)
{
	return (s->_count == 0);
}

bool isFull(Stack* s)
{
	return (s->_count == s->_maxSize);
}