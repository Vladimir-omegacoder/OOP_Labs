#pragma once
#include <iostream>
#include <math.h>




#ifndef BASIC_GRAPHICS_VECTOR



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



template<class T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& a)
{
	out << a.x << ' ' << a.y;

	return out;
}

template<class T>
std::istream& operator>>(std::istream& in, Vector<T>& a)
{
	in >> a.x >> a.y;

	return in;
}





template class Vector<int>;
using Vector2i = Vector<int>;

template class Vector<float>;
using Vector2f = Vector<float>;



#define BASIC_GRAPHICS_VECTOR

#endif // BASIC_GRAPHICS_VECTOR



#ifndef BASIC_GRAPHICS_TRANSFORM



class Transform
{

protected:

	float m_matrix[9];



	friend Transform operator*(const Transform& a, const Transform& b);

	friend Transform& operator*=(Transform& a, const Transform& b);

	friend bool operator==(const Transform& a, const Transform& b);

	friend bool operator!=(const Transform& a, const Transform& b);


public:

	Transform() :
		m_matrix{ 1, 0, 0,  0, 1, 0,  0, 0, 1 } {}

	Transform(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22) :
		m_matrix{ a00, a01, a02,  a10, a11, a12,  a20, a21, a22 } {}



	Transform& move(const Vector2f& offset);

	Transform& rotate(float angle);

	Transform& scale(const Vector2f& factor);



	Vector2f transform_point(const Vector2f& point) const;



	float& operator[](const int index);

	float operator[](const int index) const;

	const float* get_matrix();

	const float* const get_matrix() const;

};



#define BASIC_GRAPHICS_TRANSFORM

#endif // BASIC_GRAPHICS_TRANSFORM



#ifndef BASIC_GRAPHICS_SHAPE



class Shape
{

public:

	virtual ~Shape() {}

	virtual void move(const Vector2f& offset) = 0;

	virtual void rotate(float angle) = 0;

	virtual void scale(const Vector2f& factor) = 0;

	virtual void apply_transform(const Transform& transform) = 0;

};

#define BASIC_GRAPHICS_SHAPE

#endif // BASIC_GRAPHICS_SHAPE



#ifndef BASIC_GRAPHICS_RECTANGLE



class Rectangle : public Shape
{

private:

	friend class Convex_reshape;


protected:

	Vector2f m_vertices[4];

	Vector2f m_size;


public:

	Rectangle() : Rectangle(Vector2f(0, 0), Vector2f(0, 0)) {}

	Rectangle(const Vector2f& size, const Vector2f& pos);



	Vector2f get_pos() const;

	Vector2f get_size() const;

	void set_size(const Vector2f& size);



	virtual void move(const Vector2f& offset) override;

	virtual void rotate(float angle) override;

	virtual void scale(const Vector2f& factor) override;

	virtual void apply_transform(const Transform& transform) override;



	friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

	friend std::istream& operator>>(std::istream& in, Rectangle& rect);

};



#define BASIC_GRAPHICS_RECTANGLE

#endif // BASIC_GRAPHICS_RECTANGLE



#ifndef BASIC_GRAPHICS_CIRCLE



class Circle : public Shape
{

private:

	friend class Convex_reshape;


protected:

	Vector2f m_vertices[32];

	Vector2f m_pos;

	float m_radius;


public:

	Circle() : Circle(0, Vector2f(0, 0)) {}

	Circle(float radius, const Vector2f& pos);


	Vector2f get_pos() const;

	float get_radius() const;

	void set_radius(float radius);



	virtual void move(const Vector2f& offset) override;

	virtual void rotate(float angle) override;

	virtual void scale(const Vector2f& factor) override;

	virtual void apply_transform(const Transform& transform) override;



	friend std::ostream& operator<<(std::ostream& out, const Circle& circle);

	friend std::istream& operator>>(std::istream& in, Circle& circle);

};



#define BASIC_GRAPHICS_CIRCLE

#endif // BASIC_GRAPHICS_CIRCLE



#ifndef BASIC_GRAPHICS_CONVEX



class Convex : public Shape
{

private:

	friend class Convex_reshape;


protected:

	Vector2f* m_vertices;

	size_t m_vertex_count;


public:

	Convex(size_t vertex_count);

	Convex(const Convex& other);

	Convex& operator=(const Convex& other);

	~Convex() { delete[] m_vertices; }



	Vector2f& operator[](int index);

	Vector2f operator[](int index) const;



	virtual void move(const Vector2f& offset);

	virtual void rotate(float angle);

	virtual void scale(const Vector2f& factor);

	virtual void apply_transform(const Transform& transform);



	friend std::ostream& operator<<(std::ostream& out, const Convex& convex);

	friend std::istream& operator>>(std::istream& in, Convex& convex);

};



#define BASIC_GRAPHICS_CONVEX

#endif // BASIC_GRAPHICS_CONVEX



#ifndef BASIC_GRAPHICS_CONVEX_RESHAPE



class Convex_reshape
{

private:

	Convex* m_convex;


public:

	Convex_reshape(Convex& convex) : m_convex(&convex) {}



	Convex_reshape& operator()(Convex& convex)
	{
		m_convex = &convex;
		return *this;
	}



	Convex_reshape& operator=(const Rectangle& rectangle)
	{

		delete m_convex->m_vertices;
		m_convex->m_vertex_count = 4;
		m_convex->m_vertices = new Vector2f[4]
		{
			rectangle.m_vertices[0],
			rectangle.m_vertices[1],
			rectangle.m_vertices[2],
			rectangle.m_vertices[3],
		};

		return *this;

	}

	Convex_reshape& operator=(const Circle& circle)
	{

		delete m_convex->m_vertices;
		m_convex->m_vertex_count = 32;
		m_convex->m_vertices = new Vector2f[32];

		for (int i = 0; i < 32; i++)
		{
			m_convex->m_vertices[i] = circle.m_vertices[i];
		}

		return *this;

	}

};



#define BASIC_GRAPHICS_CONVEX_RESHAPE

#endif // BASIC_GRAPHICS_CONVEX_RESHAPE
