#include "Node.h"

// 배열일 경우에는 {}를 씀
Node::Node() : data(0), next(nullptr) {}

Node::~Node() {}

Node::Node(const int& data) : data(data), next(nullptr) 
{
	// 밑에처럼 초기화해도 되고, 위의 :를 활용해도 괜찮음
	// this->data = data;
}

void Node::setData(const int& data)
{
	this->data = data;
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