#pragma once

#include "vector.h"
#include "color.h"

class Light
{
public:
	Vector pos;
	Color color;

	Light() { }
	Light(Vector p, Color c) : pos(p), color(c) { }
};

