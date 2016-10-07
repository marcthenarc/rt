#pragma once

#include <string>
	using std::string;

#include "vector.h"
#include "ray.h"
#include "surface.h"

class Thing
{
protected:

	string name;

public:

	Surface *surface;

	Thing() { }
   	virtual bool Intersect(const Ray &ray, double &dist) = 0;
	virtual Vector Normal(const Vector &pos) = 0;
};
