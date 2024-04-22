#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	int age;
	string university;

public:
	Student();
	~Student();
	void set();
	void printInfo();
};

#endif