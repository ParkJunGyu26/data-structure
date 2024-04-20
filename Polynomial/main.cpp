#include "Polynomial.h"

int main(void)
{
	Polynomial a, b, c, d;
	
	a.read();	
	b.read();
	c.add(a, b);
	d.sub(a, b);
	
	a.display();
	b.display();
	c.display();
	d.display();
	
	return 0;
}