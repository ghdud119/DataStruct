#pragma once
#include<iostream>
#include<vector>

template<typename T>
class MaxHeap
{
private:
	//1base, left = 2*i, right = 2*i+1
	std::vector<T> heap;

public:
	MaxHeap()
	{
		heap.push_back(-1);
	}

	void Insert(T Data)
	{
		heap.push_back(Data);
		for (int index = heap.size(); index >= 1; index /= 2)
		{
			std::swap(heap[index], heap[index / 2]);
		}
	}

	T Pop()
	{
		if (IsEmpty()) 
			return;

		int parant = 1;
		int child = 2;

		T returnData = heap[1];
		heap[1] = heap.back();
		heap.pop_back();

		while (child < heap.size())
		{
			if (heap[child] < heap[child + 1])
				child++;
			if (heap[parant] < heap[child])
				swap(heap[parant], heap[child]);

			parant = child;
			child *= 2;
		}
		return returnData;
	}

	T Top()
	{
		if (IsEmpty())
			return;
		else
			return heap[1];
	}

	bool IsEmpty() const
	{
		return heap.size() <= 1;
	}

	void Clear()
	{
		heap.clear();
		heap.push_back(-1);
	}
};