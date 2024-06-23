#include "LinkedStack.h"

LinkedStack::LinkedStack() : top(nullptr) {}

LinkedStack::~LinkedStack() 
{
	while (!isEmpty())
	{
		Node* temp = pop();
		delete temp;
	}
}

bool LinkedStack::isEmpty() 
{
	return top == nullptr;
}

// void LinkedStack::push(int data)
// {
// 	// new는 생성자인데, 인자 값이 있는 것임
// 	// 그리고 주소값을 넘겨야됨.
// 	// 따라서 newNode은 '포인터 변수'가 되어야 함.
// 	Node* newNode = new Node(data);
// 	newNode->setNext(top);
// 	top = newNode;
// }

void LinkedStack::push(int data)
{
	Node* newNode = new Node(data);

	// 이렇게, 새로 추가할 때를 안했음
	if(isEmpty()) top = newNode;
	else {
		newNode -> setNext(top);
		top = newNode;
	}
}

Node* LinkedStack::pop()
{
	if(isEmpty())
	{
		cout << "LinkedStack is Empty" << endl;
		return nullptr;
	}

	Node* target = top;
	top = top->getNext();
	target->setNext(nullptr); // 이거를 안했음
	return target;
}

int LinkedStack::peek()
{
	if(isEmpty()) {
		cout << "Stack is EMPTY" << endl;
		exit(1);
	}
		// return -1;
	return top->getData();
}

void LinkedStack::display()
{
	if(isEmpty())
	{
		cout << "LinkedList is Empty" << endl;
		exit(1);
	}

	Node* current = top;
	while (current->getNext() != nullptr)
	{
		cout << current->getData() << "  ";
		current = current->getNext();
	}
	cout << endl;
}