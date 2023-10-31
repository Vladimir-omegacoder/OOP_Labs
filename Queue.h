#pragma once
#include <iostream>

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
	int size;

public:

	Queue();

	Queue(const Queue<T>& other);

	~Queue();


	const T& operator[] (const int index) const;
	T& operator[] (const int index);


	int getSize() const { return size; }


	void push(T data);



	void pop();

	void clear();



	void Print_Queue();
};

#include "Queue.inl"