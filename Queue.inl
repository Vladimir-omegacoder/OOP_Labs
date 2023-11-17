#include "Queue.h"

template<typename T>
inline Queue<T>::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}


template<typename T>
inline Queue<T>::Queue(const Queue<T>& other) : size(0), head(nullptr), tail(nullptr)
{

	for (Node<T>* n = other.head; n != nullptr; n = n->pNext)
	{
		push(n->data);
	}
}

template<typename T>
inline Queue<T>::~Queue()
{
	clear();
}



template<typename T>
std::ostream& operator << (std::ostream& out, const Queue<T>& queue)
{
	for (int i = 0; i < queue.getSize(); i++)
	{
		out << queue[i] << '\n';
	}

	return out;
}




template<typename T>
void Queue<T>::push(T data)
{
	Node<T> *node = new Node<T>(data);

	if (head == nullptr)
	{
		head = tail = node;
	}
	else
	{
		
		tail = tail->pNext = node;
	}
	size++;
}




template<typename T>
inline void Queue<T>::pop()
{
	if (size == 0) return;

	Node<T>* temp = head->pNext;
	delete head;
	head = temp;

	size--;
}


template<typename T>
inline void Queue<T>::clear()
{
	while (size!=0)
	{
		pop();
	}
}






template<typename T>
inline void Queue<T>::Print_Queue()
{
	for (Node<T>* i = this->head; i != nullptr; i = i->pNext)
	{
		std::cout << i->data << '\n';
	}
}



template<typename T>
inline const T& Queue<T>::operator[] (const int index) const
{
	Node<T>* current = this->head;

	if (index >= size || index < 0)
	{
		throw "Incorrect index";
	}


	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			return current->data;
		}
		current = current->pNext;
	}
}

template<typename T>
inline T& Queue<T>::operator[] (const int index) 
{
	Node<T>* current = this->head;

	if (index >= size || index < 0)
	{
		throw "Incorrect index";
	}


	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			return current->data;
		}
		current = current->pNext;
	}
}

