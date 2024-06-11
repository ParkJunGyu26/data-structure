#include <iostream>
#include <string>

using namespace std;
#define MAX_SIZE 3

int main() {
	int y1, m1, d1;
	int y2, m2, d2;
	int f = 0;

	scanf("%d/%d/%d", &y1, &m1, &d1);
	scanf("%d/%d/%d", &y2, &m2, &d2);

	if (y1 > y2)		f = 2;
	else if (y1 < y2)	f = 1;
	else if (m1 > m2)	f = 2;
	else if (m1 < m2)	f = 1;
	else if (d1 > d2)	f = 2;
	else if (d1 < d2)	f = 1;
	else f = 3;

	if (f == 1) printf("%04d/%02d/%02d\n", y1, m1, d1);
	else if (f == 2) printf("%04d/%02d/%02d\n", y2, m2, d2);
	else printf("%04d/%02d/%02d*\n", y1, m1, d1);
}