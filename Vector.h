#pragma once





template <class T>
class Vector 
{

public:

	T x;
	T y;



	Vector();

	Vector(T x, T y);
	
};





template<class T>
Vector<T> operator+(const Vector<T>& a);

template<class T>
Vector<T> operator-(const Vector<T>& a);



template<class T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b);

template<class T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b);

template<class T>
Vector<T>& operator+=(Vector<T>& a, const Vector<T>& b);

template<class T>
Vector<T>& operator-=(Vector<T>& a, const Vector<T>& b);



template<class T>
Vector<T> operator*(const Vector<T>& a, const T k);

template<class T>
Vector<T> operator*(const T k, const Vector<T>& a);

template<class T>
Vector<T>& operator*=(Vector<T>& a, const T k);



template<class T>
Vector<T> operator/(const Vector<T>& a, const T k);

template<class T>
Vector<T>& operator/=(Vector<T>& a, const T k);



template<class T>
bool operator==(const Vector<T>& a, const Vector<T>& b);

template<class T>
bool operator!=(const Vector<T>& a, const Vector<T>& b);





template class Vector<int>;
using Vector2i = Vector<int>;

template class Vector<float>;
using Vector2f = Vector<float>;