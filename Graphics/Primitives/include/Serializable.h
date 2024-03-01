#pragma once
#include <fstream>





class Serializable
{

public:

	virtual ~Serializable() {}

	virtual void serialize(std::ofstream& out) const = 0;

	virtual void deserialize(std::ifstream& in) = 0;

	static void serialize(std::ofstream& out, const Serializable& obj)
	{
		obj.serialize(out);
	}

	static void deserialize(std::ifstream& in, Serializable& obj)
	{
		obj.deserialize(in);
	}

};