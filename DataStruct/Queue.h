#pragma onece
#include<iostream>

template<typename T, size_t Capacity>
class Queue
{
private:
	T elements[Capacity];

	size_t front;
	size_t rear;

public:
	Queue() :front(0), rear(0) {}

	bool isEmpty() const 
	{
		return front == rear;
	}

	void enqueue(T Data)
	{
		if ((rear + 1) % Capacity == front)
		{
			std::cerr << "queue is full, Cannot enqueue" << std::endl;
			return;
		}
		elements[rear] = Data;
		rear = (rear + 1) % Capacity;
	}

	T Dequeue()
	{
		if (isEmpty())
		{
			std::cerr << "queue is empty, Cannot dequeue" << std::endl;
			return;
		}
		 T returnData = elements[front];
		 front = (front + 1) % Capacity;
		 return returnData;
	}
};