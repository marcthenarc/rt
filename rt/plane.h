#pragma once

#include "thing.h"

class Plane : public Thing
{
	Vector norm;
	double offset;

public:

	Plane();
	Plane(const Vector &n, double o, Surface *s);
	Vector Normal(const Vector &pos);
	bool Intersect(const Ray &ray, double &dist);
};
