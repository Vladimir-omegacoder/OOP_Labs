#pragma once
#include <iostream>
#include "Customer.h"
#include "Queue.h"
#include <string>


class Cash_register
{
private:

	Queue<Customer> queue;
	int max_size;
	int time;

public:

	Cash_register();

	Cash_register(const Cash_register& other);

	Cash_register(int max_size, int time);

	

	~Cash_register();


	const Customer& operator[] (const int index) const;
	Customer& operator[] (const int index);



	int getMaxSize() const { return max_size; }

	void setMaxSize(const int max_size) { this->max_size = max_size; }


	int getSize() const { return queue.getSize(); }


	int getTime() const { return time; }

	void setTime(const int time) { this->time = time; }


	void push(Customer data);




	void pop();

	void clear();



	Cash_register& operator= (const Cash_register& other);

	friend bool operator == (const Cash_register& cash1, const Cash_register& cash2);
	friend bool operator != (const Cash_register& cash1, const Cash_register& cash2);

	friend std::ostream& operator << (std::ostream& out, const Cash_register& cash);
	friend std::istream& operator >> (std::istream& in, Cash_register& cash);
};

#include "Cash_register.inl"