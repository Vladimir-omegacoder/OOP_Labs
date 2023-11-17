#include "Cash.h"


Cash::Cash()
{
	max_size = 0;
	time = 0;
}


Cash::Cash(int max_size, int time)
{
	this->max_size = max_size;
	this->time = time;
}


Cash::Cash(const Cash& other) : max_size(other.max_size), time(other.time), queue(other.queue)
{
}


Cash::~Cash()
{
	queue.clear();
}






const int& Cash::operator[](const int index) const
{
	return queue[index];
}

int& Cash::operator[](const int index)
{
	return queue[index];
}






void Cash::push(int data)
{
	if (queue.getSize() == max_size)
	{
		std::cout << "Черга заповнена!\n";
		return;
	}
	else
	{
		queue.push(data);
	}
}




void Cash::pop()
{
	queue.pop();
}


void Cash::clear()
{
	queue.clear();
}





Cash& Cash::operator=(const Cash& other)
{
	if (this == &other)
	{
		return *this;
	}

	clear();

	max_size = other.max_size;
	time = other.time;

	for (int i = 0; i < other.getSize(); i++)
	{
		push(other.queue[i]);
	}

	return *this;
}


std::ostream& operator << (std::ostream& out, const Cash& cash)
{
	out << "Час обслуговування покупця: " << cash.getTime() << "\tМаксимальна довжина черги: " << cash.getMaxSize() << "\tДовжина черги: " << cash.getSize() << "\n";

	for (int i = 0; i < cash.getSize(); i++)
	{
		out << cash[i] << '\n';
	}

	return out;
}


 std::istream& operator>>(std::istream& in, Cash& cash)
{
	in >> cash.max_size;
	in.ignore(1);
	in >> cash.time;

	return in;
}



Cash::Smart_Queue Cash::operator()(int i, int j)
{
	if (i == this->queue.getSize() - 1 || i < 0 || j <= 0)
	{
		throw std::out_of_range("NOOOOO");
	}


	Smart_Queue qu(this);


	qu.count = i + j;
	qu.j = j;

	int count = 0;
	if (i + j > qu.cash->getSize())
	{
		count = qu.cash->getSize();
	}

	else
	{
		count = i + j;
	}


	Node* current = qu.cash->queue.head;

	for (int ii = 0; ii < count - 1; ii++)
	{
		if (ii == i)
		{
			qu.start = current;
		}
		current = current->pNext;
	}

	qu.end = current;


	return qu;
}
