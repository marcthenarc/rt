#pragma once

#include "color.h"
#include <math.h>

class Surface 
{
public:
	double roughness;

	Surface() { }
	virtual Color diffuse(Vector pos) = 0;
	virtual Color specular(Vector pos) = 0;
	virtual double reflect(Vector pos) = 0;
};

class ShinySurface : public Surface
{
public:

	ShinySurface() { roughness = 250; }
	Color diffuse(Vector pos) { return Color::white; }
	Color specular(Vector pos) { return Color::grey; }
	double reflect(Vector pos) { return 0.7; }
};

class CheckerboardSurface : public Surface
{
public:

	CheckerboardSurface() { roughness = 150; }
	Color diffuse(Vector pos)
	{
		if ( ((int)floor(pos.z) + (int)floor(pos.x)) % 2 != 0)
			return Color::white;

		return Color::black;
	}

	Color specular(Vector pos) { return Color::white; }
	double reflect(Vector pos)
	{
		if ( ((int)floor(pos.z) + (int)floor(pos.x)) % 2 != 0)
			return 0.1;

		return 0.7;
    }
};

