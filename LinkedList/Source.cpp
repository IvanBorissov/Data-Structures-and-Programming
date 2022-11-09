#include <iostream>
#include "LinkedList.hpp"
#include "DoubleLinkedList.hpp"
using namespace std;

int main()
{
	LinkedList<int>L;

	L.pushBack(3);
	L.pushBack(4);
	L.pushBack(5);
	L.pushFront(2);
	L.pushFront(1);

	L.print();

	L.popFront();
	L.popFront();

	L.print();

	cout << L.back() << endl;
	cout << L.front() << endl;

	LinkedList<int>L2 = L;
	LinkedList<int>L3;

	L3 = L;

	L2.print();
	L3.print();

	L2 = concatenation(L2, L3);
	L2.print();

	return 0;
}
