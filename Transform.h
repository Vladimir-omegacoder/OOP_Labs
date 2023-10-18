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



	Transform& move(const Vector2f& offset)
	{
		Transform moving;

		moving.m_matrix[0] = 0;
		moving.m_matrix[1] = 0;
		moving.m_matrix[2] = 0;

		moving.m_matrix[3] = 0;
		moving.m_matrix[4] = 0;
		moving.m_matrix[5] = 0;

		moving.m_matrix[6] = offset.x;
		moving.m_matrix[7] = offset.y;
		moving.m_matrix[8] = 0;

		(*this) *= moving;

		return *this;
	}

	Transform& rotate(float angle)
	{
		Transform rotation;

		angle /= 57.2958f;

		rotation.m_matrix[0] = cosf(angle);
		rotation.m_matrix[1] = -sinf(angle);
		rotation.m_matrix[2] = 0;

		rotation.m_matrix[3] = sinf(angle);
		rotation.m_matrix[4] = cos(angle);
		rotation.m_matrix[5] = 0;

		rotation.m_matrix[6] = 0;
		rotation.m_matrix[7] = 0;
		rotation.m_matrix[8] = 0;

		(*this) *= rotation;

		return *this;
	}

	Transform& scale(const Vector2f& factor)
	{
		Transform scaling;

		scaling.m_matrix[0] = factor.x;
		scaling.m_matrix[1] = 0;
		scaling.m_matrix[2] = 0;

		scaling.m_matrix[3] = 0;
		scaling.m_matrix[4] = factor.y;
		scaling.m_matrix[5] = 0;

		scaling.m_matrix[6] = 0;
		scaling.m_matrix[7] = 0;
		scaling.m_matrix[8] = 0;

		(*this) *= scaling;

		return *this;
	}



	Vector2f transform_point(const Vector2f& point)
	{
		float vector_line[3] { point.x, point.y, 1 };
		float result_vector_line[3];

		for (int i = 0; i < 3; ++i)
		{
			result_vector_line[i] =
				vector_line[0] * m_matrix[i] +
				vector_line[1] * m_matrix[i + 3] +
				vector_line[2] * m_matrix[i + 6];
		}

		return Vector2f(result_vector_line[0], result_vector_line[1]);
	}



	float& operator[](const int index)
	{
		return m_matrix[index];
	}

	float operator[](const int index) const
	{
		return m_matrix[index];
	}

	const float* get_matrix()
	{
		return m_matrix;
	}

	const float*const get_matrix() const
	{
		return m_matrix;
	}

};



Transform operator*(const Transform &a, const Transform &b)
{

	Transform new_transform;

	for(int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			new_transform.m_matrix[i * 3 + j] =
				a.m_matrix[i * 3] * b.m_matrix[j] +
				a.m_matrix[i * 3 + 1] * b.m_matrix[j + 3] +
				a.m_matrix[i * 3 + 2] * b.m_matrix[j + 6];
		}
	}

	return new_transform;

}

Transform& operator*=(Transform& a, const Transform& b)
{

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			a.m_matrix[i * 3 + j] =
				a.m_matrix[i * 3] * b.m_matrix[j] +
				a.m_matrix[i * 3 + 1] * b.m_matrix[j + 3] +
				a.m_matrix[i * 3 + 2] * b.m_matrix[j + 6];
		}
	}

	return a;

}

bool operator==(const Transform& a, const Transform& b)
{
	
	for (int i = 0; i < 9; ++i)
	{
		if(a.m_matrix[i] != b.m_matrix[i])
		{
			return false;
		}
	}

}

bool operator!=(const Transform& a, const Transform& b)
{

	for (int i = 0; i < 9; ++i)
	{
		if (a.m_matrix[i] == b.m_matrix[i])
		{
			return false;
		}
	}

}


