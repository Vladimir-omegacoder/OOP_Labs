#pragma once
#include <iostream>
#include <string>

class Customer
{
private:
	std::string name;
	
public:
	Customer(std::string name = "")
	{
		this->name = name;
	}

	friend bool operator == (const Customer& cas1, const Customer& cas2)
	{
		return cas1.name == cas2.name;
	}
	friend bool operator != (const Customer& cas1, const Customer& cas2)
	{
		return !(cas1==cas2);
	}
	friend std::ostream& operator << (std::ostream& out, const Customer& cas) { return out << cas.name; }

	Customer& operator= (const Customer& cas)
	{
		if (*this == cas)
		{
			return *this;
		}

		name = cas.name;

		return *this;
	}
};

