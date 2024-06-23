#include <iostream>

using namespace std;

int main()
{
   // /*
   // int a[5] = { 2,4,8,10,15 };
   // int* p = a;

   // cout << "\ncase 1\n";
   // cout << *p++ << endl;
   // cout << p[0] << " " << p[1] << endl;

   // cout << "\ncase 2\n";
   // cout << *++p << endl;
   // cout << p[0] << " " <<  p[1] << endl;

   // cout << "\ncase 3\n";
   // cout << *(--p)++ << endl;
   // cout << p[0] << " " << p[1] << " " << p[2] << endl;
   // */

   int a[5] = { 1,2,3,4,5 };
   int b[3] = { 6,7,8 };
   int c[2] = { 10,15 };
   int d = 25;

   int* p[4] = {a,b,c,&d};
   int** pp = p;

   cout << "case 1\n";
   cout << **pp + 1 << endl;
   cout << *(*pp + 1) + 1 << endl;
   cout << **(pp + 2) + 1 << endl;
   cout << *(*(p+1)+2) << endl;
   cout << *p + 3 << " " << *(p + 3) << " " << **(p + 3) << endl;
}