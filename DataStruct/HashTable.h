#pragma once
#include<iostream>
#include<vector>
#include<list>

template<typename KeyType, typename DataType>
class HashTable
{
private:
	std::vector<std::list<std::pair<KeyType, DataType>>> table;
	size_t size;

public:
	HashTable(size_t Size) : size(Size)
	{
		table.resize(size);
	}

	size_t HashFunction(const KeyType& Key)
	{
		return Key % size;
	}

	void Insert(const KeyType& Key, const DataType& Data)
	{
		size_t index = HashFunction(Key);
		table[index].push_back(Key, Data);
	}

	bool Search(const KeyType& Key, DataType& Result)
	{
		size_t index = HashFunction(Key);
		for (const auto& entry : table[index])
		{
			if (entry.first == Key)
			{
				Result = entry.second;
				return true;
			}
		}
		return false;
	}

	bool Remove(const KeyType& Key)
	{
		size_t index = HashFunction(Key);
		for (const auto& entry : table[index])
		{
			if (entry->first == Key)
			{
				entry.remove();
				return true;
			}
		}
		return false;
	}
};

