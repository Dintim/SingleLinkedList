//#include "SingleLinkedList.h"



//template<class T>
//SingleLinkedList<T>::SingleLinkedList()
//{
//	head = nullptr;
//	size = 0;
//}
//
//template<class T>
//SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& obj)
//{
//}
//
//template<class T>
//SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T>& obj)
//{
//	// TODO: вставьте здесь оператор return
//}
//
//template<class T>
//SingleLinkedList<T>::SingleLinkedList(SingleLinkedList<T>&& obj)
//{
//}
//
//template<class T>
//SingleLinkedList<T>& SingleLinkedList<T>::operator=(SingleLinkedList<T>&& obj)
//{
//	// TODO: вставьте здесь оператор return
//}
//
//template<class T>
//void SingleLinkedList<T>::push_back(const T & obj)
//{
//	elem<T>*newElem = new elem<T>;
//	newElem->obj = obj;
//	newElem->next = nullptr;
//	if (head == nullptr) {
//		head = newElem;
//		size = 1;
//		return;
//	}
//
//	cursor = head;
//	while (cursor->next != nullptr)
//		cursor = cursor->next;
//
//	cursor->next = newElem;
//	this->size++;
//}
//
//template<class T>
//void SingleLinkedList<T>::push_front(const T & obj)
//{
//	elem<T>*newElem = new elem<T>;
//	newElem->obj = obj;
//	newElem->next = head;
//	head = newElem;
//	this->size++;
//}
//
//template<class T>
//void SingleLinkedList<T>::insert(const T & obj, int position)
//{
//	if (position > size || position < 0)
//		return;
//	if (position == 0) {
//		push_front(obj);
//		return;
//	}
//	if (position == size) {
//		push_back(obj);
//		return;
//	}
//
//	elem<T>*newElem = new elem<T>;
//	newElem->obj = obj;
//	cursor = head;
//	for (size_t i = 0; i < position - 1; i++)
//	{
//		cursor = cursor->next;
//	}
//	newElem->next = cursor->next;
//	cursor->next = newElem;
//	size++;
//}
//
////template<class T>
////void SingleLinkedList<T>::erase(size_t position)
////{	
////	if (position > size)
////		return;
////	if (position == 0) {
////		pop_front();
////		return;
////	}
////	if (position == size - 1) {
////		pop_back();
////		return;
////	}
////	cursor = head;
////	elem<T>*tmp = new elem<T>;
////
////	for (size_t i = 0; i < length; i++)
////	{
////
////	}
////
////}
//
//template<class T>
//void SingleLinkedList<T>::pop_back()
//{
//	if (size == 0)
//		return;
//	if (size > 0) {
//		if (size == 1) {
//			delete head;
//			size = 0;
//			head = nullptr;
//			return;
//		}
//		cursor = head;
//		for (size_t i = 0; i < size - 1; i++)
//		{
//			cursor = cursor->next;
//		}
//		delete cursor->next;
//		cursor->next = nullptr;
//		size--;
//	}
//}
//
//template<class T>
//void SingleLinkedList<T>::pop_front()
//{
//	if (size == 0)
//		return;
//	if (size == 1) {
//		delete head;
//		head = nullptr;
//		size = 0;
//		return;
//	}
//	cursor = head->next;
//	delete head;
//	head = cursor;
//	size--;
//}
//
//template<class T>
//SingleLinkedList<T>::~SingleLinkedList()
//{
//}



