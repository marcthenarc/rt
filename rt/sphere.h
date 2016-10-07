#pragma once

#include "thing.h"

class Sphere : public Thing
{
	double radius2;
	Vector center;

public:

	Sphere();
	Sphere(const Vector &c, double r, Surface *s);
	Vector Normal(const Vector &pos);
	bool Intersect(const Ray &ray, double &dist);
};
