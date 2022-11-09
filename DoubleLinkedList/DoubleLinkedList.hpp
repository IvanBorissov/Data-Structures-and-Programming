#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T data;
	Node* prev = nullptr;
	Node* next = nullptr;

	Node(T data)
	{
		this->data = data;
	}
};

template<typename T>
class DoubleLinkedList
{
private:
	size_t count = 0;
	Node<T>* head;
	Node<T>* tail;

	void Copy(const DoubleLinkedList& other);
	void Erase();

public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& other);
	DoubleLinkedList<T>& operator= (const DoubleLinkedList& other);
	~DoubleLinkedList();

	void pushBack(const T& element);
	void pushFront(const T& element);

	void popBack();
	void popFront();

	const T& front() const;
	const T& back() const;

	void print() const;
	size_t getSize() const;
	bool empty() const;
};

template<typename T>
void DoubleLinkedList<T>::Copy(const DoubleLinkedList& other)
{
	Node<T>* ptr = other.head;

	while (ptr)
	{
		pushBack(ptr->data);
		ptr = ptr->next;
	}
}

template<typename T>
void DoubleLinkedList<T>::Erase()
{
	Node<T>* ptr;
	Node<T>* curr = head;

	while (curr)
	{
		ptr = curr;
		curr = curr->next;
		delete ptr;
	}
	head = tail = nullptr;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	head = tail = nullptr;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList& other)
{
	Copy(other);
}

template<typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList& other)
{
	if (this != &other)
	{
		Erase();
		Copy(other);
	}
	return *this;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Erase();
}

template<typename T>
void DoubleLinkedList<T>::pushBack(const T& element)
{
	Node<T>* ptr = new Node<T>(element);
	count++;

	if (empty())
	{
		head = tail = ptr;
		return;
	}

	tail->next = ptr;
	ptr->prev = tail;
	tail = ptr;
}

template<typename T>
void DoubleLinkedList<T>::pushFront(const T& element)
{
	Node<T>* ptr = new Node<T>(element);
	count++;

	if (empty())
	{
		head = tail = ptr;
		return;
	}

	head->prev = ptr;
	ptr->next = head;
	head = ptr;
}

template<typename T>
void DoubleLinkedList<T>::popBack()
{
	if (empty())
	{
		throw std::runtime_error("Can't pop from an empty list");
	}
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
	}

	Node<T>* ptr = tail;
	tail = tail->prev;
	delete ptr;
	count--;
}

template<typename T>
void DoubleLinkedList<T>::popFront()
{
	if (empty())
	{
		throw std::runtime_error("Can't pop from an empty list");
	}
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
	}

	Node<T>* ptr = head;
	head = head->next;
	delete ptr;
	count--;
}

template<typename T>
const T& DoubleLinkedList<T>::front() const
{
	if (empty())
	{
		throw std::runtime_error("Empty list");
	}
	return head->data;
}

template<typename T>
const T& DoubleLinkedList<T>::back() const
{
	if (empty())
	{
		throw std::runtime_error("Empty list");
	}
	return tail->data;
}

template<typename T>
void DoubleLinkedList<T>::print() const
{
	Node<T>* ptr = head;
	while (ptr)
	{
		std::cout << ptr->data;
		if (ptr != tail)
		{
			std::cout << "<->";
		}
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

template<typename T>
size_t DoubleLinkedList<T>::getSize() const
{
	return count;
}

template<typename T>
bool DoubleLinkedList<T>::empty() const
{
	return head == nullptr && tail == nullptr;
}
