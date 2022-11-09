#ifndef LINKEDSTACK
#define LINKEDSTACK

#include<iostream>

template<typename T>
struct Element
{
	T data; ///data part of the cell
	Element<T>* next; ///pointer to the next element in the stack
};

template<typename T>
class LinkedStack
{
private:
	Element<T>* Top; ///pointer to the first element of the stack

	void copy(LinkedStack const&);
	void erase();

public:
	///big four, because we use dynamic memory
	LinkedStack();
	LinkedStack(LinkedStack const&);
	LinkedStack& operator=(LinkedStack const& other);
	~LinkedStack();

	///basic operations of the Stack data structure
	bool empty()const;
	void push(T const&);
	void pop();
	T const& top()const;
};

template<typename T>
void LinkedStack<T>::copy(LinkedStack const& otherStack)
{
	if (otherStack.Top == nullptr)
	{
		///if the stack we want to copy is empty, we create a new empty stack
		Top = nullptr;
		return;
	}

	///stack is not empty, so we create a new top element which for now copies the data from otherStack.top and its next element is nullptr
	Top = new Element<T>{ otherStack.Top->data, nullptr };
	
	///our current element is not always gonna be the Top element, so we need this pointer in order to make the link between elements
	Element<T>* currElement = Top;

	///we need to save the position of the next element somewhere in order to extract its data
	Element<T>* nextElement = otherStack.Top->next;

	///next itterates the otherStack's elements, and by design when we reach the bottom of the stack bottomElement->next = nullptr
	while (nextElement != nullptr)
	{
		///we connect the current element to a new element with copied data from otherStack and nullptr, because it is currently the last element of the stack
		currElement->next = new Element<T>{ nextElement->data, nullptr };
		
		///traversing down the stack
		currElement = currElement->next;

		///goes to the next element of otherStack
		nextElement = nextElement->next;
	}

}

template<typename T>
void LinkedStack<T>::erase()
{
	///using already developed function to itterate through the stack and delete every element of it
	while (!empty())
	{
		pop();
	}
}

template<typename T>
LinkedStack<T>::LinkedStack()
{
	Top = nullptr;
}

template<typename T>
LinkedStack<T>::LinkedStack(LinkedStack const& otherStack)
{
	copy(otherStack);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T> const& other) 
{
	if (this != &other) {
		erase();
		copyStack(other);
	}
	return *this;
}

template<typename T>
LinkedStack<T>::~LinkedStack()
{
	erase();
}

template<typename T>
inline bool LinkedStack<T>::empty() const
{
	return Top == nullptr;
}

template<typename T>
inline void LinkedStack<T>::push(T const& element)
{
	///creating a new element which houses the given data and has link to the old top
	Element<T>* tempPtr = new Element<T>{ element, Top};
	Top = tempPtr;
}

template<typename T>
void LinkedStack<T>::pop()
{
	if (empty())
	{
		throw std::runtime_error("can't delete the top element of an empty stack");
	}

	///redirecting the top pointer to one element below the current top element
	Element<T>* tempPtr = Top;
	Top = Top->next;
	delete tempPtr;
}

template<typename T>
T const& LinkedStack<T>::top() const
{
	if (empty())
	{
		throw std::runtime_error("can't get the top element of an empty stack!");
	}
	return Top->data;
}

#endif
