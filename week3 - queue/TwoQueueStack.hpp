#pragma once

#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class TwoQueueStack
{
private:
	queue<T>s1;
	queue<T>s2;
public:
	void push(T const& x);
	void pop();
	T const& top() const;
	bool empty()const;
};

template<typename T>
void TwoQueueStack<T>::push(T const& x)
{
	if (s1.empty())
	{
		s1.push(x);
		while (!s2.empty())
		{
			s1.push(s2.front());
			s2.pop();
		}
	}
	else
	{
		s2.push(x);
		while (!s1.empty())
		{
			s2.push(s1.front());
			s1.pop();
		}
	}

}

template<typename T>
void TwoQueueStack<T>::pop()
{
	if (s1.empty() && s2.empty())
	{
		throw std::runtime_error("You can not delete the top element of an empty stack!");
	}
	if (s1.empty())
	{
		s2.pop();
	}
	else
	{
		s1.pop();
	}
}

template<typename T>
T const& TwoQueueStack<T>::top() const
{
	if (s1.empty() && s2.empty())
	{
		throw std::runtime_error("You can not access the top element of an empty stack!");
	}
	if (s1.empty())
	{
		return s2.front();
	}
	else
	{
		return s1.front();
	}
}

template<typename T>
bool TwoQueueStack<T>::empty() const
{
	return s1.empty() && s2.empty();
}
