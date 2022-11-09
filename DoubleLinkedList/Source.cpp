#include <iostream>
#include "DoubleLinkedList.hpp"
using namespace std;

int main()
{
	DoubleLinkedList<int>L;

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

	DoubleLinkedList<int>L2 = L;
	DoubleLinkedList<int>L3;

	L3 = L;

	L2.print();
	L3.print();

	return 0;
}
