#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string name;
	int age;
	string occupation;

public:
	// 디폴트 생성자
	Person();
	
	// 매개변수 생성자
	Person(string n, int a, string o);

	// 소멸자
	~Person();
	
	void set();
	void displayInfo();
	void wishGoodDay();
};

#endif