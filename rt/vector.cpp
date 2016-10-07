#include <iostream>
	using std::cout;
	using std::endl;

#include <math.h>

#include "vector.h"


Vector::Vector() : x(0), y(0), z(0)
{

}

Vector::Vector(double a, double b, double c) : x(a), y(b), z(c)
{

}

const Vector & Vector::operator += (const Vector& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

Vector Vector::operator * (double t)
{
	return Vector(x * t, y * t, z * t);
}

Vector Vector::operator / (double t)
{
	return Vector(x / t, y / t, z / t);
}

double Vector::Mag()
{
	return sqrt(x * x + y * y + z * z);
}

Vector Vector::GetNorm()
{
	double mag = Mag();

	if (mag == 0)
		throw "Division by zero";

	return *this / mag;
}

void Vector::Normalize()
{
	*this = GetNorm();
}

void Vector::Print()
{
	cout << "<" << x << ", " << y << ", " << z << ">" << endl;
}

Vector operator - (const Vector &a, const Vector &b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator + (const Vector &a, const Vector &b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

double Dot(const Vector &v1, const Vector &v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector Cross(const Vector &v1, const Vector &v2)
{
	return Vector(	v1.y * v2.z - v1.z * v2.y,
					v1.z * v2.x - v1.x * v2.z,
					v1.x * v2.y - v1.y * v2.x);
}

