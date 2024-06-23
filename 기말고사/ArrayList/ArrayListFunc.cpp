#include "ArrayList.h"

ArrayList::ArrayList() : length(0), data{0} {}

ArrayList::~ArrayList() {}

bool ArrayList::isEmpty() 
{
	return length == 0;
}

bool ArrayList::isFull()
{
	return length == MAX_LIST_SIZE;
}

// 정상범주라면 pos < 0 과 pos > length 로 안해도 됨
void ArrayList::insert(int pos, int item)
{
	if(isFull() || pos < 0 || pos > size())
	{
		cout << "ERROR!" << endl;
		exit(1);
	}

	for (int i = length; i > pos; i--)
		data[i] = data[i-1];

	data[pos] = item;
	length++;
}

int ArrayList::remove(int pos)
{
	if(isEmpty() || pos < 0 || pos > size())
	{
		cout << "ArrayList is Empty" << endl;
		exit(1);
	}

	int removedItem = data[pos];

	for (int i = pos; i < length-1; i++)
		data[i] = data[i+1];

	length--;
	return removedItem;
}

bool ArrayList::find(int item)
{
	for (int i = 0; i < size(); i++)
	{
		if (data[i] == item)
			return true;
	}

	return false;
}

int ArrayList::getEntry(int pos)
{
	if (isEmpty() || pos < 0 || pos >= size())
	{
		cout << "ERROR!" << endl;
		// return -1; 
		exit(1);
	}

	return data[pos];
}

void ArrayList::replace(int pos, int item)
{
	if (isEmpty() || pos < 0 || pos >= size())
	{
		cout << "ERROR!" << endl;
		exit(1);
	}

	data[pos] = item;
}

int ArrayList::size()
{
	return length;
}

void ArrayList::display()
{
	if (isEmpty())
	{
		cout << "ArrayList is Empty" << endl;
		exit(1);
	}

	for (int i = 0; i < size(); i++)
		cout << data[i] << "  ";
	cout << endl;
}

void ArrayList::clear()
{
	length = 0;
}