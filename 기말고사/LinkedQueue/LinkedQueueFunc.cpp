#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() : front(nullptr), rear(nullptr)
{
	// 이렇게 해도 되고, 위처럼 해도 됨
	// front = rear = nullptr;
}

LinkedQueue::~LinkedQueue() 
{
	while(!isEmpty())
	{
		Node* temp = dequeue();
		delete temp;
	}
}

bool LinkedQueue::isEmpty()
{
	// return front == rear;
	// front 와 rear가 같아질 수 있음... 
	// 그게 바로 노드가 하나 있을 경우
	return front == nullptr;
}

// 스택과 동일하게 push 해주면 됨.
// 다만, 여기에서는 top이 아닌 rear
void LinkedQueue::enqueue(int data)
{
	// 새로운 노드 값을 동적 할당
	Node* newNode = new Node(data);

	if(isEmpty()) front = rear = newNode;
	else {
		rear -> setNext(newNode);
		rear = newNode;
	}

	// 현재 맨 뒤에 있는 값에 대하여
	// 새로운 노드가 next가 되도록
	// rear->setNext(newNode);

	// 결국 맨 뒤의 값은
	// 새로 만들어진 값으로 할당
	// rear = newNode;

	// gpt 코드
	// Node* newNode = new Node(data);
	// if (isEmpty())
	// {
	// 	front = rear = newNode;
	// } else
	// {
	// 	rear->setNext(newNode);
	// 	rear = newNode;
	// }
}

Node* LinkedQueue::dequeue()
{
	if(isEmpty())
	{
		cout << "LinkedQueue is Empty" << endl;
		return nullptr;
	}

	Node* removedNode = front;
	front = removedNode->getNext();
	removedNode -> setNext(nullptr);
	if(front==nullptr) rear = nullptr;

	return removedNode;

	// 삭제된 값을 반환해줘야되므로
	// 변수 하나 초기화
	// Node* removedItem = front->getNext();

	// front는 한 칸 앞으로 밀어줘야됨
	// 그래서 front의 next는 현재 삭제되는 값으로 되어있음
	// 이 부분을 삭제되는 값 다음 값으로
	// 할당해줘야 됨.
	// front->setNext(removedItem->getNext());

	// return removedItem;

	// gpt 코드
	// Node* target = front;
	// front = front->getNext();
	// if (front == nullptr)
	// rear = nullptr;
	// return target;
}

// 큐의 제일 앞에 있는 값을 출력
// 즉, front 값 출력
int LinkedQueue::peek()
{
	if(isEmpty())
	{
		cout << "LinkedQueue is Empty" << endl;
		exit(1);
	}

	Node* current = front->getNext();

	// rear 값의 다음은
	// nullptr 이므로
	// 이를 활용
	while (current->getNext() != nullptr)
	{
		current = current->getNext();
	}

	// rear에 해당하는 값을 출력
	return current->getData();

	// gpt 코드
	// return front->getData();
}

void LinkedQueue::display()
{
	if(isEmpty())
	{
		cout << "LinkedQueue is Empty" << endl;
		exit(1);
	}

	Node* current = front;
	while(current != nullptr) 
	{
		cout << current->getData() << "  ";
		current = current->getNext();
	}
	cout << endl;

	// Node* current = front->getNext();

	// rear 값의 다음은
	// nullptr 이므로
	// 이를 활용
	// while (current->getNext() != nullptr)
	// {
	// 	cout << current->getData() << "  ";
	// 	current = current->getNext();
	// }
	// cout << endl;

	// gpt 코드
	// Node* current = front;
	// while (current != nullptr)
	// {
	// 	cout << current->getData() << "  ";
	// 	current = current->getNext();
	// }
	// cout << endl;
}