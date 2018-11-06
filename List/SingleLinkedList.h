#pragma once
#include <iostream>
using namespace std;

template<class T>
struct elem {
	T obj;
	elem<T> *next;
};

template<class T>
class SingleLinkedList
{
	elem<T>*head;
	int size;
	elem<T>*cursor;

public:
	SingleLinkedList();
	SingleLinkedList(const SingleLinkedList<T>&anotherList);
	SingleLinkedList<T>&operator=(const SingleLinkedList<T>&anotherList);
	SingleLinkedList(SingleLinkedList<T>&&anotherList);
	SingleLinkedList<T>&operator=(SingleLinkedList<T>&&anotherList);
	void push_back(const T&obj);
	void push_front(const T&obj);
	void insert(const T&obj, int position);
	void erase(size_t position);
	void pop_back();
	void pop_front();
	void print();
	~SingleLinkedList();
};

template<class T>
SingleLinkedList<T>::SingleLinkedList()
{
	head = nullptr;
	size = 0;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& anotherList)
{
	if (anotherList.size == 0) {
		head = nullptr;
		size = 0;
		return;
	}	
	elem<T>*tmp = new elem<T>;
	tmp=anotherList.head;
	for (size_t i = 0; i < anotherList.size; i++)
	{
		push_back(tmp->obj);
		tmp = tmp->next;
	}
	size = anotherList.size;
	delete tmp;
}

template<class T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T>& anotherList)
{
	if (this == &anotherList)
		return *this;

	if (anotherList.size == 0) {
		this->~SingleLinkedList();
		return *this;
	}
	this->~SingleLinkedList();
	elem<T>*tmp = new elem<T>;
	tmp = anotherList.head;
	for (size_t i = 0; i < anotherList.size; i++)
	{
		push_back(tmp->obj);
		tmp = tmp->next;
	}
	size = anotherList.size;
	delete tmp;	

	return *this;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(SingleLinkedList<T>&& anotherList)
{
	this->head = anotherList.head;
	this->size = anotherList.size;
	anotherList.head = nullptr;
	anotherList.size = 0;
}

template<class T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(SingleLinkedList<T>&& anotherList)
{
	swap(this->head, anotherList.head);
	swap(this->size, anotherList.size);
	return *this;
}

template<class T>
void SingleLinkedList<T>::push_back(const T & obj)
{
	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	newElem->next = nullptr;
	if (head == nullptr) {
		head = newElem;
		size = 1;
		return;
	}
	cursor = head;
	while (cursor->next != nullptr)
		cursor = cursor->next;

	cursor->next = newElem;
	this->size++;
}

template<class T>
void SingleLinkedList<T>::push_front(const T & obj)
{
	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	newElem->next = head;
	head = newElem;
	this->size++;
}

template<class T>
void SingleLinkedList<T>::insert(const T & obj, int position)
{
	if (position > size || position < 0)
		return;
	if (position == 0) {
		push_front(obj);
		return;
	}
	if (position == size) {
		push_back(obj);
		return;
	}

	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	cursor = head;
	for (size_t i = 0; i < position - 1; i++)
	{
		cursor = cursor->next;
	}
	newElem->next = cursor->next;
	cursor->next = newElem;
	size++;
}

template<class T>
void SingleLinkedList<T>::erase(size_t position)
{	
	if (position > size)
		return;
	if (position == 0) {
		pop_front();
		return;
	}
	if (position == size - 1) {
		pop_back();
		return;
	}
	cursor = head;
	elem<T>*tmp = new elem<T>;
	for (size_t i = 0; i < position; i++)
	{
		cursor = cursor->next;
	}
	tmp->next = cursor->next;
	cursor = head;
	for (size_t i = 0; i < position-1; i++)
	{
		cursor = cursor->next;
	}
	delete cursor->next;
	cursor->next = tmp->next;
	delete tmp;
	tmp = nullptr;
	size--;
}

template<class T>
void SingleLinkedList<T>::pop_back()
{
	if (size == 0)
		return;
	if (size > 0) {
		if (size == 1) {
			delete head;
			size = 0;
			head = nullptr;
			return;
		}
		cursor = head;
		for (size_t i = 0; i < size - 1; i++)
		{
			cursor = cursor->next;
		}
		delete cursor->next;
		cursor->next = nullptr;
		size--;
	}
}

template<class T>
void SingleLinkedList<T>::pop_front()
{
	if (size == 0)
		return;
	if (size == 1) {
		delete head;
		head = nullptr;
		size = 0;
		return;
	}
	cursor = head->next;
	delete head;
	head = cursor;
	size--;
}

template<class T>
inline void SingleLinkedList<T>::print()
{
	cursor = head;
	for (size_t i = 0; i < size; i++)
	{
		cout << cursor->obj << " ";
		cursor = cursor->next;		
	}
	cout << endl;
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList()
{
	while (size > 0) {
		pop_back();		
	}
	head = nullptr;
	size = 0;
}

