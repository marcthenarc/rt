#include "sphere.h"
#include <math.h>
#include <stdlib.h>

Sphere::Sphere() : radius2(1)
{
	name = "Sphere";
}

Sphere::Sphere(const Vector &c, double r, Surface *s) : center(c), radius2(r * r)
{
	surface = s;
	name = "Sphere";
}

Vector Sphere::Normal(const Vector &pos)
{
	return (pos - center).GetNorm();
}

bool Sphere::Intersect(const Ray &ray, double &dist)
{
	Vector eo = center - ray.start;
	double v = Dot(eo, ray.dir);

    if (v >= 0)
	{
    	double disc = radius2 - (Dot(eo, eo) - v * v);

		if (disc >= 0)
		{
			dist = v - sqrt(disc);
			return true;
		}
    }

	return false;
}
