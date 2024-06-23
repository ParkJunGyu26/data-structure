#include "Node.h"

Node::Node() : data(0), next(nullptr), prev(nullptr) {}

Node::Node(const int val) : data(val), next(nullptr), prev(nullptr) {}

Node::~Node() {}

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

void Node::setPrev(Node* prev) 
{
	this->prev = prev;
}

Node* Node::getPrev() 
{
	return prev;
}