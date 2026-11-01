#include <iostream>
#include "LinkedList.h"

Node* addNode(Node* head, Node* node)
{
	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		node->next = head;
	}
	return node;
}

Node* removeNode(Node* head)
{
	if (head == nullptr) return nullptr;

	Node* newHead = head->next;
	delete head;
	return newHead;
}