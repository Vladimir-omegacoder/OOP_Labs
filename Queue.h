#pragma once
#include <iostream>
#include <string>

template<typename T>
class Queue
{
private:
	template <typename T>
	struct Node
	{
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	Node<T>* tail;
	int max_size;
	int size;
	int time;

public:

	Queue();

	Queue(int max_size = 0, int time = 0);

	Queue(const Queue<T>& other);

	~Queue();


	T& operator[] (const int index);



	int getSize() { return size; }


	void push(T data);




	void pop();

	void clear();



	void Print_Queue();
};

#include "Queue.inl"