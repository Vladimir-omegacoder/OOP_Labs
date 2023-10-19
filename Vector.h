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
Vector<T> operator+(const Vector<T>& a)
{
	return Vector<T>(a);
}

template<class T>
Vector<T> operator-(const Vector<T>& a)
{
	return Vector<T>(-a.x, -a.y);
}



template<class T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
{
	return Vector<T>(a.x + b.x, a.y + b.y);
}

template<class T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b)
{
	return Vector<T>(a.x - b.x, a.y - b.y);
}

template<class T>
Vector<T>& operator+=(Vector<T>& a, const Vector<T>& b)
{
	a.x += b.x;
	a.y += b.y;

	return a;
}

template<class T>
Vector<T>& operator-=(Vector<T>& a, const Vector<T>& b)
{
	a.x -= b.x;
	a.y -= b.y;

	return a;
}



template<class T>
Vector<T> operator*(const Vector<T>& a, const T k)
{
	return Vector<T>(a.x * k, a.y * k);
}

template<class T>
Vector<T> operator*(const T k, const Vector<T>& a)
{
	return Vector<T>(k * a.x, k * a.y);
}

template<class T>
Vector<T>& operator*=(Vector<T>& a, const T k)
{
	a.x *= k;
	a.y *= k;

	return a;
}



template<class T>
Vector<T> operator/(const Vector<T>& a, const T k)
{
	return Vector<T>(a.x / k, a.y / k);
}

template<class T>
Vector<T>& operator/=(Vector<T>& a, const T k)
{
	a.x /= k;
	a.y /= k;

	return a;
}



template<class T>
bool operator==(const Vector<T>& a, const Vector<T>& b)
{
	return (a.x == b.x && a.y == b.y);
}

template<class T>
bool operator!=(const Vector<T>& a, const Vector<T>& b)
{
	return (a.x != b.x || a.y != b.y);
}





template class Vector<int>;
using Vector2i = Vector<int>;

template class Vector<float>;
using Vector2f = Vector<float>;