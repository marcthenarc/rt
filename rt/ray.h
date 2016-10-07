#pragma once

#include "vector.h"

class Ray
{
public:
	Vector start;
	Vector dir;

	Ray() { }
	Ray (const Vector &s, const Vector &d) : start(s), dir(d) { }
};

