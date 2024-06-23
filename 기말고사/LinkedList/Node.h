#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

using namespace std;

class Node
{
private:
	int data;						// 해당 값
	Node* next;						// 다음 값을 가리키는 포인터 주소(순차)

public:
	Node();
	Node(const int val);			// 매개변수 값으로 데이터 초기화
	~Node();

	void setData(const int val);	// 매개변수 값으로 데이터 초기화
	int getData() const;					// 해당 값 조회

	void setNext(Node* next);		// 매개변수 값으로 다음 값 포인터 주소 할당
	Node* getNext() const;				// 다음 값 포인터 주소 조회

	// Node* getNext() const;		메서드가 '객체의 멤버 변수'를 변경하지 않음
	// const Node* getNext();		'메서드 반환 값'이 상수임
};

#endif