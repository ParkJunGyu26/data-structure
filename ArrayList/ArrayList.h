#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include <iostream>

#define MAX_LIST_SIZE 50

using namespace std;

class ArrayList
{
private:
	int data[MAX_LIST_SIZE];
	int length;

public:
	ArrayList();
	~ArrayList();

	bool isEmpty();
	bool isFull();

	void insert(int pos, int item);
	int remove(int pos);
	bool find(int item);

	int getEntry(int pos);
	void replace(int pos, int item);
	int size();

	void display();
	void clear();

};

#endif