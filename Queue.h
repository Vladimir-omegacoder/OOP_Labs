#pragma once
#include <iostream>
#include "Cash.h"

template<typename T>
class Queue
{

	friend class Cash;


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

template <typename T>
std::ostream& operator << (std::ostream& out, const Queue<T>& queue);

#include "Queue.inl"