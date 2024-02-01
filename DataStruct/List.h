#pragma once
#include<iostream>

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(T Data) : data(Data), next(nullptr) {}
};

template<typename T>
class List
{
private:
	Node<T>* head;

public:
	List() : head(nullptr) {};

	void Push(T Data)
	{
		Node<T>* newNode = new Node<T>(Data);
		newNode->next = head;
		head = newNode;
	}

	void PrintList()
	{
		Node<T> current = head;

		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	T* Search(T Data)
	{
		Node<T>* current = head;

		while (current != nullptr)
		{
			if (current->data == Data)
				return true;
		}
		return false;
	}

	void Delete(T Data)
	{
		Node<T>* current = head;
		Node<T>* before = head;
		while (current != nullptr)
		{
			if (current->data == Data)
			{
				before->next = current->next;
				delete current;
			}			
			before = current;
			current = current->next;
		}
	}
};

