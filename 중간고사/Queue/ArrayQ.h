#ifndef _ArrayQ_H__
#define _ArrayQ_H__

#include <iostream>
#define MAX_QUEUE_SIZE 30

using namespace std;

class ArrayQ
{
private:
    int queue[MAX_QUEUE_SIZE];
    int front; // 제거되는 공간
    int rear; // 추가되는 공간

public:
    ArrayQ(); // 생성자
    ~ArrayQ(); // 소멸자

    bool isEmpty(); // 큐가 비어있으면 true를, 아니면 false를 반환
    bool isFull(); // 큐가 가득 차 있으면 true를, 아니면 false를 반환

    void enqueue(int e); // 주어진 요소 e를 큐 맨 뒤에 추가
    int dequeue(); // 큐가 비어있지 않다면, 맨 앞 요소를 삭제하고 반환
    int peek(); // 큐가 비어있지 않다면 맨 앞 요소를 삭제하지 않고 반환
    void display(); // 큐의 모든 요소들 출력
    int size(); // 큐의 모든 요소들의 개수 반환
};

#endif