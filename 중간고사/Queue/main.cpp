#include "ArrayQ.h"

int main()
{
    ArrayQ Q;
    char select = '\0', ch = '\0';

    cout << "I/E/V/X : ";
    cin >> select;

    while (select != 'X' && select != 'x') {
        switch (select) {
            case 'I': case 'i':
                cin >> ch;
                Q.enqueue(ch);
                break;
            case 'E': case 'e':
                ch = Q.dequeue();
                cout << "dequeue : " << ch << endl;
                break;
            case 'V': case 'v':
                ch = Q.peek();
                cout << "peek : " << ch << endl;
                break;
            default:
                cout << "Wrong input!" << endl;
                break;
        }
        cout << "I/E/V/X : ";
        cin >> select;
    }

    Q.display();

    return 0;
}