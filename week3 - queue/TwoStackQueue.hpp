/*#pragma once

#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class TwoStackQueue
{
private:
	stack<T>s1;
	stack<T>s2;
public:
	void push(T const& x);
	void pop();
	T const& front() const;
	bool empty()const;
};

template<typename T>
void TwoStackQueue<T>::push(T const& x)
{
	s1.push(x);
}

template<typename T>
void TwoStackQueue<T>::pop()
{
	if (s1.empty())
	{
		throw std::runtime_error("You can not delete the front element of an empty queue!");
	}
	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	s2.pop();
	while (!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

template<typename T>
T const& TwoStackQueue<T>::front() const
{
	if (s1.empty())
	{
		throw std::runtime_error("You can not delete the front element of an empty queue!");
	}
	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	T data = s2.top();
	while (!s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
	return data;
}

template<typename T>
bool TwoStackQueue<T>::empty() const
{
	return s1.empty();
}
*/