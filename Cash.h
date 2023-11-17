#pragma once
#include <iostream>
#include "Queue.h"
#include <string>

class Cash
{
private:

	using Node = Queue<int>::Node<int>;


	class Smart_Queue
	{
	public:

		Node* start;
		Node* end;
		Cash* cash;

		int j = 0;
		int count = 0;

		Smart_Queue(Cash* cash)
		{
			this->cash = cash;
			int j = 0;
			int count = 0;

			start = nullptr;
			end = nullptr;
		}

		Cash& operator = (Queue<int>& other)
		{
			if (other.getSize() == 0 || cash->queue.getSize() < 2)
			{
				throw std::length_error("NOOOOO");
			}

			int temp_j = 0;

			if (this->j <= other.getSize())
			{
				temp_j = j;
			}
			else if (this->j > other.getSize())
			{
				temp_j = other.getSize();
			}


			Node* s2 = start->pNext;


			for (int i = 0; i < temp_j && s2 != nullptr; i++)
			{
				Node* temp = s2;
				s2 = s2->pNext;

				delete temp;
			}

			start->pNext = other.head;


			Node* temp = other.head;

			for (int i = 1; i < temp_j; i++)
			{
				temp = temp->pNext;
			}

			Node* next = temp->pNext;

			end = temp;
			end->pNext = s2;

			while (next)
			{
				Node* te = next;
				next = next->pNext;

				delete te;
			}

			other.head = nullptr;
			other.tail = nullptr;
			other.size = 0;

			return *this->cash;
		}

	};




	Queue<int> queue;
	int max_size;
	int time;

public:

	Cash();

	Cash(const Cash& other);

	Cash(int max_size, int time);



	~Cash();


	const int& operator[] (const int index) const;
	int& operator[] (const int index);


	Cash& operator= (const Cash& other);

	friend std::ostream& operator << (std::ostream& out, const Cash& cash);
	friend std::istream& operator >> (std::istream& in, Cash& cash);


	Smart_Queue operator ()(int i, int j);



	int getMaxSize() const { return max_size; }

	void setMaxSize(const int max_size) { this->max_size = max_size; }


	int getSize() const { return queue.getSize(); }


	int getTime() const { return time; }

	void setTime(const int time) { this->time = time; }


	void push(int data);




	void pop();

	void clear();
};

