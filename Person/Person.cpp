#include "Person.h"

Person::Person() {
	name = "";
	age = 0;
	occupation = "";
}

// this는 해당 객체(인스턴스)의 주소값을 가리키므로 -> 으로 멤버에 접근한다.
Person::Person(string n, int a, string o) {
	name = n;			// this->name = name;
	age = a;			// this->age = age;
	occupation = o;		// this->occupation = occupation;
}

Person::~Person() {
	cout << name << " Person 클래스가 소멸되었습니다." << endl;
}

void Person::set() {
	cin >> name >> age >> occupation;
}

void Person::displayInfo() {
	cout << "name : " << name << endl;
	cout << "age : " << age << endl;
	cout << "occupation : " << occupation << endl;
}

void Person::wishGoodDay() {
	cout << "Have a good day, " << name << " !" << endl;
}

