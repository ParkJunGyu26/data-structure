#include "Node.h"

Node::Node() : data(0), next(nullptr) {}

Node::~Node() {}

Node::Node(const int& data) : next(nullptr)
{
	this->data=data;
}

void Node::setData(const int& data) 
{
	this->data=data;
}

int Node::getData() 
{
	return data;
}

void Node::setNext(Node* next) 
{
	this->next=next;
}

Node* Node::getNext() 
{
	return next;
}