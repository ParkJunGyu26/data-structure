#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>

using namespace std;

class Calculator
{
private:
	int num1;
	int num2;

public:
	Calculator();
	~Calculator();
	int sub(int n1, int n2);
	double div(int n1, int n2);
	void set(int n1, int n2);
	void display();
};

#endif