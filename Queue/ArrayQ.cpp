#include "ArrayQ.h"

int i;

// 생성자
ArrayQ::ArrayQ() {
    front = 0;
    rear = 0;
};

// 소멸자
ArrayQ::~ArrayQ() {};

// 큐가 비었는지 체크
bool ArrayQ::isEmpty() {
    return front == rear;
}

// 큐가 꽉 찼는지 체크
bool ArrayQ::isFull() {
    return rear == MAX_QUEUE_SIZE;
}

// 삽입
void ArrayQ::enqueue(int e) {
    if (isFull()) {
        cout << "Queue is Full";
    } else {
        queue[rear] = e;
        rear++;
    }
}

// 삭제
int ArrayQ::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty";
        return 0;
    } else {
        return queue[front++];
    }
}

// 삭제하지 않고 반환
int ArrayQ::peek() {
    if (isEmpty()) {
        cout << "Queue is Empty";
        return 0;
    } else {
        return queue[front];
    }
}

// 출력
void ArrayQ::display() {
    if (isEmpty()) {
        cout << "Queue is Empty";
    } else {
        for (i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

// 개수 반환
int ArrayQ::size() {
    if (isEmpty()) return 0;
    int cnt = 0;
    for (i = front; i <= rear; i++) cnt++;
    return cnt;
}