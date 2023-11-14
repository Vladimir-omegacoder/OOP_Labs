#pragma once
#include "Vector.h"
#include <math.h>



class Transform
{

protected:

	float m_matrix[9];



	friend Transform operator*(const Transform& a, const Transform& b);

	friend Transform& operator*=(Transform& a, const Transform& b);

	friend bool operator==(const Transform& a, const Transform& b);

	friend bool operator!=(const Transform& a, const Transform& b);


public:

	Transform(): 
		m_matrix{ 1, 0, 0,  0, 1, 0,  0, 0, 1 }{}

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






