#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct Node
{
	int value;
	Node* next;

} Node;

Node* addNode(Node* head, Node* node);
Node* removeNode(Node* head);

#endif 