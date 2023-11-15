#pragma once







template <class T>
class Smart_ptr
{

private:

	T* m_ptr;


public:

	Smart_ptr() : m_ptr(nullptr) {}

	Smart_ptr(T* ptr) : m_ptr(ptr) {}

	Smart_ptr(const Smart_ptr&) = delete;
	Smart_ptr& operator=(const Smart_ptr&) = delete;
	
	Smart_ptr(Smart_ptr&& other) : m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}
	Smart_ptr& operator=(Smart_ptr&& other)
	{
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
		return *this;
	}

	~Smart_ptr()
	{
		delete m_ptr;
	}





};



#include "Smart_ptr.inl"

