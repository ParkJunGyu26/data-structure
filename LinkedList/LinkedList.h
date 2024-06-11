#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include "Node.h"

// 단일 링크드 리스트이므로 head만 필요
class LinkedList
{
private:
	Node head;

public:
	LinkedList();			// 생성자
	~LinkedList();			// 소멸자

	Node* getHead();		// 해당 링크드 리스트의 head 주소 값 반환
	bool isEmpty();			// 해당 링크드 리스트가 빈 값인지

	int getEntry(int pos);	// 해당 매개변수 위치의 값 반환

	void insert(int pos, const int data);  // 해당 매개변수의 위치에 해당 매개변수의 데이터를 삽입
	Node* rmv(int pos);		// 해당 매개변수 위치의 값을 제거

	bool find(int data);	// 해당 매개변수 값을 탐색
	void replace(int pos, const int data);	// 해당 매개변수의 위치에 해당 매개변수의 데이터로 교체

	int size();			// 해당 링크드 리스트의 크기 반환
	void showList();	// 해당 링크드 리스트 조회
	void clear();		// 해당 링크드 리스트 주소값 반납

	int calcSum();		// 해당 링크드 리스트의 데이터 값들의 모든 합
	int countNode(int val);	// 해당 매개변수 데이터의 개수를 반환
	void reverse();		// 해당 링크드 리스트의 순서를 뒤집는
	void merge(LinkedList* that);	// 링크드 리스트를 서로 결합
};

#endif