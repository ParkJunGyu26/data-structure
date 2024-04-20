#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#define MAX_ARRAY 100
#include <iostream>

using namespace std;

class Polynomial
{
private:
	int degree;
	int coef[MAX_ARRAY];

public:
	Polynomial();
	~Polynomial();

	void read();
	void add(Polynomial a, Polynomial b);
	void mul(Polynomial a, Polynomial b);
	void sub(Polynomial a, Polynomial b);
	void trim();
	void display();
};

#endif