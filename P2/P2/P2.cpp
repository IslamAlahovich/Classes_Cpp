#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
	struct element
	{
		T data;
		element *next;
	};
	element *head;
	List(const List&) = delete; // запрет использования констр. копирования
	void operator= (const List&) = delete; // запрет использования поератора присв.
public:
	List(T new_data);
	~List();
	void push(T new_data);
	void pop();
	void fpush(T new_data);
	void fpop();
	void show()
	{
		element* ptr = head;
		while (ptr)
		{
			cout << ptr->data << "   ";
			ptr = ptr->next;
		}
		cout << endl;
	}
};

template <typename T>
List<T>::List(T new_data) 
{
	head = new element;
	head->data = new_data;
	head->next = NULL;
}

template <typename T>
List<T>::~List() //деструктор
{
	element* next_del = head->next;
	while (next_del)
	{
		delete head;
		head = next_del;
		next_del = next_del->next;
	}
	delete head;
}

template <typename T>
void List<T>::push(T new_data) // операция вставки
{
	element* new_elem = new element;
	new_elem->data = new_data;
	new_elem->next = head;
	head = new_elem;
}

template <typename T>
void List<T>::pop() // операция удаления
{
	element* del_elem = head;
	head = head->next;
	delete del_elem;
}

template <typename T>
void List<T>::fpush(T new_data) // операция вставки в конец списка
{
	element* new_elem = new element;
	new_elem->data = new_data;
	new_elem->next = NULL;
	element* foot = head;
	while (foot->next) { foot = foot->next; }
	foot->next = new_elem;
}

template <typename T>
void List<T>::fpop() // операция удаления послед. элемента
{
	element* fdel_elem = head;
	while (fdel_elem->next->next) { fdel_elem = fdel_elem->next; }
	delete fdel_elem->next;
	fdel_elem->next = NULL;
}

int main()
{
	List<int> myList(5);
	
	cout << "dobavim elementi 3 i 4: ";
	myList.push(4);
	myList.push(3);
	myList.show();
	
	cout << "udalim posledniy: ";
	myList.pop();
	myList.show();

	cout << "dobavim element 1488 v konec: ";
	myList.fpush(1488);
	myList.show();

	cout << "udalim posledniy: ";
	myList.fpop();
	myList.show();

	return 0;
}