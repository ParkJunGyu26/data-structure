#include "Node.h"

// <피드백>
// 생성자에서 data도 0으로 초기화 꼭 해주기
// 매개변수 생성자라도, data를 val로 초기화 해주기
// const는 상수
// 메서드 뒤에 const는 해당 멤버 객체를 보호하는 느낌?
// 타입 앞에 const는 반환된 최종 값을 상수로 취급
// 매개변수와 클래스의 멤버가 동일하다면, this를 사용

// 생성자
Node::Node() : data(0), next(nullptr) {}

// 매개변수 생성자
// 매개변수에 대한 새로운 Node 객체 동적 할당
Node::Node(const int val) : data(val), next(nullptr) {}

// 소멸자
Node::~Node() {}

// 매개변수에 대한 새로운 Node 객체 동적 할당
void Node::setData(const int val) 
{
	data = val;
}

// 해당 객체의 data 변수 반환
int Node::getData() const
{
	return data;
}

// 해당 객체에 대한 next 값을 매개변수로 할당
void Node::setNext(Node* next) 
{
	this->next = next;
}

// 해당 객체의 next 포인터 변수 반환
Node* Node::getNext() const
{
	return next;
}