#include "Student.h"

Student::Student() {
	name = "";
	age = 0;
	university = "";
}

Student::~Student() {}

void Student::set() {
	cin >> name >> age >> university;
}

void Student::printInfo() {
	cout << "이름은 " << name << endl;
	cout << "나이는 " << age << endl;
	cout << "학교는 " << university << endl;
}