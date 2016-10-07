#pragma once

class Vector
{
public:

	double x,y,z;

	Vector();
	Vector(double a, double b, double c);

	const Vector & operator += (const Vector& v);
	Vector operator * (double x);
	Vector operator / (double x);
	double Mag();
	Vector GetNorm();
	void Normalize();
	void Print();

};

Vector operator - (const Vector &a, const Vector &b);
Vector operator + (const Vector &a, const Vector &b);
double Dot(const Vector &v1, const Vector &v2);
Vector Cross(const Vector &v1, const Vector &v2);
