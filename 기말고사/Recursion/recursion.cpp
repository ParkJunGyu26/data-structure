#include <iostream>
#include <string>

using namespace std;

string reverse(string st, int cnt)
{
	if (cnt == st.size())
		return "";
	return reverse(st, cnt+1) + st[cnt];
}

int main2()
{
	string st;
	cin >> st;

	string answer = reverse(st, 0);
	cout << answer << endl;
}