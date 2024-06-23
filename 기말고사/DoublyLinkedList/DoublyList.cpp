#include "DoublyList.h"

DoublyList::DoublyList() : head(), listsize(0) {}

DoublyList::~DoublyList() 
{
	clear();
}

// head 주소 자체를 가져오기 떄문에
// 첫 번째 노드를 조회하기 위해선
// getHead를 조회한 이후에 getNext 해줘야 된다.
Node* DoublyList::getHead() 
{
	// return head.getNext();
	return &head;
}

bool DoublyList::isEmpty() 
{
	// return head.getNext() == nullptr;
	return listsize == 0;
}

int DoublyList::size() 
{
	return listsize;
}

int DoublyList::getEntry(int pos) 
{
	if (isEmpty() || pos < 0 || pos > listsize)
	{
		cout << "ERROR!" << endl;
		return -1;
	}

	Node* current = getHead()->getNext();

	for (int i = 0; i < pos; i++)
		current = current->getNext();

	return current->getData();
}

void DoublyList::insert(int pos, const int data) 
{
	if (pos < 0 || pos > listsize)
	{
		cout << "ERROR !" << endl;
		return;
	}

	Node* newNode = new Node(data);

	// 헤드에 삽입할 경우
	if (pos == 0)
	{

		// 노드가 있을 경우
		if (listsize != 0)
		{
			Node* current = getHead()->getNext();

			// 새로운 노드 다음은 이전 헤드
			newNode->setNext(current);

			// 이전 헤드 이전은 새로운 노드
			current->setPrev(newNode);
		}

		// 새로운 노드 이전은 헤드로
		newNode->setPrev(getHead());

		// 헤드의 다음은 새로운 노드로
		getHead()->setNext(newNode);
	}
	else
	{
		Node* current = getHead()->getNext();

		for (int i = 0; i < pos-1; i++)
			current = current->getNext();


		// 직전 노드 다음 노드를 새로운 노드로 할당
		current->setNext(newNode);

		// 새로운 노드 이전 노드를 직전 노드로 할당
		newNode->setPrev(current);

		if (pos != size())
		{
			// 새로운 노드의 다음 값은 직전 노드의 다음 값으로 할당
			newNode->setNext(current->getNext());

			// 새로운 노드 다음 노드의 이전 값을 새로운 노드로 할당
			// 마지막 값일 경우에는 getNext 가 nullptr 나옴
			// 그래서 여기에서 에러 발생할 수 있음
			// 이 부분은 예외처리 해줘야 됨
			(current->getNext())->setPrev(newNode);
		}
	}
	listsize++;
}

Node* DoublyList::rmv(int pos) 
{
	if (isEmpty() || pos < 0 || pos > listsize)
	{
		cout << "ERROR!" << endl;
		return nullptr;
	}

	Node* removedItem = nullptr;

	// 헤드를 지울 경우
	if (pos == 0)
	{
		// 첫 번째 노드를 반환할 변수에 할당
		removedItem = getHead()->getNext();

		if (listsize == 1)
		{
			getHead()->setNext(nullptr);

		}
		else
		{
			// 헤드의 다음은 두 번째 노드로 변경
			head.setNext(removedItem->getNext());

			// 두 번째 노드의 이전은 헤드로 변경
			(removedItem->getNext())->setPrev(getHead());
		}

		removedItem->setNext(nullptr);
		removedItem->setPrev(nullptr);

	} else 
	{
		Node* current = getHead()->getNext();

		for (int i = 0; i < pos-1; i++)
			current = current->getNext();
		
		removedItem = current->getNext();

		// 제일 오른쪽 값을 삭제할 때
		if (pos == listsize-1)
		{
			// 삭제 이후의 마지막 노드 다음은 nullptr이다.
			current->setNext(nullptr);
		}

		// 중간의 값을 삭제할 때
		else 
		{
			// 삭제 노드 건너 뛰어서 가리키도록
			current->setNext(removedItem->getNext());

			// 삭제 다음 노드도 건너 뛰어서 이전 노드를 가리키도록
			(removedItem->getNext())->setPrev(current);

			// 삭제된 노드에 연결된 노드는 nullptr 처리
			removedItem->setNext(nullptr);
		}
		// 삭제된 노드에 연결된 노드는 nullptr 처리
		removedItem->setPrev(nullptr);
	}

	listsize--;

	return removedItem;
}

void DoublyList::showList() 
{
	if(isEmpty())
	{
		cout << "List is Empty" << endl;
		return;
	}

	Node* current = getHead()->getNext();

	while (current->getNext() != nullptr)
	{
		cout << current->getData() << "  ";
		current = current->getNext();
	}
	cout << endl;
}

void DoublyList::clear() 
{
	while (!isEmpty())
	{
		Node* tmp = rmv(0);
		delete tmp;
	}
}