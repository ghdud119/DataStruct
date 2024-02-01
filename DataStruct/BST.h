#pragma once

#include<iostream>

template<typename DataType>
class BST
{
private:

	struct Node
	{
		DataType data;
		int key;
		Node* parant;
		Node* leftChild;
		Node* rightChild;
		Node(int Key, DataType Data, Node* Parant, Node* LeftChild, Node* RightChild)
			:data(Data), key(Key), parant(Parant), leftChild(LeftChild), rightChild(RightChild){	}
	};	
	Node* root = nullptr;
	Node* temp = nullptr;
	Node* parant = nullptr;
	Node* LChild = nullptr;
	Node* RChild = nullptr;

public:

	bool IsEmpty() { return root == nullptr; }

	Node* Search(Node* tempNode, int Key)
	{
		if (tempNode == Nullptr)
		{
			return NULL;
		}

		if (tempNode->key == Key)
		{
			return tempNode;
		}
		else if (tempNode->key > Key)
		{
			Search(tempNode->leftChild , Key)
		}
		else
		{
			Search(tempNode->rightChild, Key)
		}
	}

	void Insert(int Key, DataType Data)
	{
		if (IsEmpty())
		{
			*root = new Node(Key, Data, Black, nullptr, nullptr, nullptr);
		}

		if(Key > )
	}
};