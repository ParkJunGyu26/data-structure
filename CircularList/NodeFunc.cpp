#include "Node.h"

Node::Node() {}

Node::~Node() {}

Node::Node(const int val) : data(val), next(nullptr) {}

void Node::setData(const int val) 
{
	data = val;
}

int Node::getData()
{
	return data;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

Node* Node::getNext()
{
	return next;
}