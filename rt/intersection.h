#pragma once

#include "thing.h"
#include "ray.h"

class Intersection
{
public:

	Thing *thing;
	Ray ray;
	double dist;

	Intersection() : thing(NULL) { }
};

