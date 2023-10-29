#include "Cash_register.h"

inline Cash_register::Cash_register()
{
	max_size = 0;
	time = 0;
}


inline Cash_register::Cash_register(int max_size, int time)
{
	this->max_size = max_size;
	this->time = time;
}


inline Cash_register::Cash_register(const Cash_register& other): max_size(other.max_size), time(other.time), queue(other.queue)
{
}


inline Cash_register::~Cash_register()
{
	queue.clear();
}






inline const Customer& Cash_register::operator[](const int index) const
{
	return queue[index];
}

inline Customer& Cash_register::operator[](const int index)
{
	return queue[index];
}






inline void Cash_register::push(Customer data)
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




inline void Cash_register::pop()
{
	queue.pop();
}


inline void Cash_register::clear()
{
	queue.clear();
}





inline Cash_register& Cash_register::operator=(const Cash_register& other)
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


inline bool operator==(const Cash_register& cash1, const Cash_register& cash2)
{
	if (cash1.getSize() != cash2.getSize())
	{
		return false;
	}

	if (cash1.getMaxSize() != cash2.getMaxSize())
	{
		return false;
	}

	for (int i = 0; i < cash1.getSize(); i++)
	{
		if (cash1[i] != cash2[i])
		{
			return false;
		}
	}

	return true;
}


inline bool operator !=(const Cash_register& cash1, const Cash_register& cash2)
{
	return !(cash1 == cash2);
}


std::ostream& operator << (std::ostream& out, const Cash_register& cash)
{
	out << "Час обслуговування покупця: " << cash.getTime() << "\tМаксимальна довжина черги: " << cash.getMaxSize() << "\tДовжина черги: " << cash.getSize() << "\n";

	for (int i = 0; i < cash.getSize(); i++)
	{
		out << cash[i] << '\n';
	}

	return out;
}


inline std::istream& operator>>(std::istream& in, Cash_register& cash)
{	
	in >> cash.max_size;
	in.ignore(1);
	in >> cash.time;

	return in;
}