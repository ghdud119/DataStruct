#pragma once
#include<iostream>

template<typename T, size_t Capacity>
class Stack
{
private:
	T elements[Capacity];
	size_t rear;

public:
	Stack() :rear(0) {}

	bool isEmpty()
	{
		return rear == 0;
	}

	void Push(T Data)
	{
		if (rear == Capacity)
		{
			std::cerr << "Stack is full, Cannot Push" << std::endl;
			return;
		}

		elements[rear] = Data;
		rear += 1;
	}

	T Pop()
	{
		if (isEmpty())
		{
			std::cerr << "Stack is empty, Cannot Pop" << std::endl;
			return;
		}
		rear--;
		return elements[rear];
	}

};