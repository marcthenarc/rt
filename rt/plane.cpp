#include <stdlib.h>

#include "plane.h"

Plane::Plane()
{
	name = "Plane";
}

Plane::Plane(const Vector &n, double o, Surface *s) : norm(n), offset(o)
{
	name = "Plane";
	surface = s;
	offset = o;
}

Vector Plane::Normal(const Vector &pos)
{
	return norm;
}

bool Plane::Intersect(const Ray &ray, double &dist)
{
	double denom = Dot(norm, ray.dir);

	if (denom > 0)
		return false;

	dist = (Dot(norm, ray.start) + offset) / (-denom);

	return true;
}
