#pragma once

template<typename T>
class Smart_Pointer
{
private:

	T* ptr;


public:

	Smart_Pointer(T*ptr)
	{
		this->ptr = ptr;
	}

	~Smart_Pointer()
	{
		delete ptr;
	}


	T& operator*()
	{
		return *ptr;
	}

	T* operator ->()
	{
		return ptr;
	}
};

