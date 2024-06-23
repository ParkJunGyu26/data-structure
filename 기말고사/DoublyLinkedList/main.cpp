#include "DoublyList.h"

int main()
{
	DoublyList dlist;

    dlist.insert(0, 10); 
    dlist.insert(1, 20);  
    dlist.insert(1, 15);  
    dlist.insert(3, 25);  
    dlist.insert(0, 5);   

    dlist.showList();

	cout << "pos 0: " << dlist.getEntry(0) << endl; 
	cout << "pos 2: " << dlist.getEntry(2) << endl; 
	cout << "pos 4: " << dlist.getEntry(4) << endl; 
   
    cout << "Size of the list: " << dlist.size() << endl;

  
    Node* removedNode = dlist.rmv(0); 
	cout << "removed 0 : " << removedNode -> getData() << endl;
    delete removedNode;
	
	removedNode = dlist.rmv(2); 
	cout << "removed 2 : " << removedNode -> getData() << endl;
    delete removedNode;
	
    dlist.showList();
    dlist.clear();

    return 0;
}