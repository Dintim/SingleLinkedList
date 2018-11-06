#include "SingleLinkedList.h"


void main()
{
	SingleLinkedList<int> s;
	s.push_back(2);
	s.push_back(4);
	s.push_back(10);
	s.insert(3, 1);
	s.insert(5, 3);
	s.print();
	s.erase(2);
	s.print();

	SingleLinkedList<int> s2;
	s2 = s;
	s2.print();
	
	system("pause");
}