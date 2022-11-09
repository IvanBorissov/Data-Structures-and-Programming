#pragma once

#include <iostream>

///single element of the linked list
template<typename T>
struct Node
{
	///contains data and pointer to the next element
	T data;
	Node* next;
	
	///base initialiser for the element
	Node(const T& data)
	{
		this->data = data;
		next = nullptr;
	}
};

template<typename T>
class LinkedList
{
private:
	///pointers to the front and back of the list
	Node<T>* head;
	Node<T>* tail;

	void Copy(const LinkedList<T>& other);
	void Erase();
public:
	///having dynamic memory requires big four
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	LinkedList<T>& operator= (const LinkedList<T>& other);
	~LinkedList();

	///basic functionality of the Linked List data structure
	void pushFront(const T& el);
	void pushBack(const T& el);
	void popFront();
	const T& front() const;
	const T& back() const;

	///additional functionaity to the class
	template<typename U>
	friend LinkedList<U> concatenation(LinkedList<U>& Left, LinkedList<U>& Right);
	void print() const;
};

template<typename T>
void LinkedList<T>::Copy(const LinkedList<T>& other)
{
	Node<T>* ptr = other.head;
	while (ptr != nullptr)
	{
		pushBack(ptr->data);
		ptr = ptr->next;
	}
}

template<typename T>
void LinkedList<T>::Erase()
{
	Node<T>* curr = head;
	while (curr != nullptr)
	{
		Node<T>* ptr = curr;
		curr = curr->next;
		delete ptr;
	}
	head = tail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	head = nullptr;
	tail = nullptr;

	Copy(other);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	if (this != &other)
	{
		Erase();
		Copy(other);
	}

	return *this;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Erase();
}

template<typename T>
void LinkedList<T>::pushFront(const T& el)
{
	Node<T>* ptr = new Node<T>(el);

	if (head == nullptr)
	{
		head = tail = ptr;
		return;
	}

	ptr->next = head;
	head = ptr;
}

template<typename T>
void LinkedList<T>::pushBack(const T& el)
{
	Node<T>* ptr = new Node<T>(el);

	if (tail == nullptr)
	{
		head = tail = ptr;
		return;
	}

	tail->next = ptr;
	tail = ptr;
}

template<typename T>
void LinkedList<T>::popFront()
{
	if (head == nullptr)
	{
		throw std::runtime_error("You can not delete the top element of an empty stack!");
	}

	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}

	Node<T>* ptr = head;
	head = head->next;
	delete ptr;
}

template<typename T>
const T& LinkedList<T>::front() const
{
	if (head == nullptr)
	{
		throw std::runtime_error("You can not delete the top element of an empty stack!");
	}

	return head->data;
}

template<typename T>
const T& LinkedList<T>::back() const
{
	if (tail == nullptr)
	{
		throw std::runtime_error("You can not delete the top element of an empty stack!");
	}

	return tail->data;
}

template<typename T>
void LinkedList<T>::print() const
{
	Node<T>* ptr = head;
	while (ptr != nullptr)
	{
		std::cout << ptr->data << " -> ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

template<typename U>
LinkedList<U> concatenation(LinkedList<U>& Left, LinkedList<U>& Right)
{
	LinkedList<U> result;

	if (Left.head == nullptr)
	{
		result.head = Right.head;
		result.tail = Right.tail;
	}
	else
		if (Right.head == nullptr)
		{
			result.head = Left.head;
			result.tail = Left.tail;
		}
		else
		{
			Left.tail->next = Right.head;
			result.head = Left.head;
			result.tail = Right.tail;
		}
	
	Right.head = Right.tail = Left.head = Left.tail = nullptr;

	return result;
}
