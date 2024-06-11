#include "Person.h"

int main()
{
	Person p1;
	Person p2("park", 20, "student");

	p1.displayInfo();
	cout << "1------" << endl;
	p2.displayInfo();
	cout << "1------" << endl;

	p1.set();
	p2.set();

	p1.displayInfo();
	cout << "2------" << endl;
	p2.displayInfo();
	cout << "2------" << endl;

	p1.wishGoodDay();
	p2.wishGoodDay();
}