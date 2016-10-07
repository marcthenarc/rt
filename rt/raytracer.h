#pragma once

#include "ray.h"
#include "scene.h"
#include "intersection.h"

class Raytracer
{
	static const int maxDepth = 5;

public:
	Raytracer();
	Intersection intersections(const Ray &ray, Scene &scene);
	bool testRay(const Ray &ray, Scene &scene, double &dist);
	Color traceRay(const Ray &ray, Scene &scene, int depth);
	Color shade(Intersection &isect, Scene &scene, int depth);
	Color getNaturalColor(Thing *thing, const Vector &pos, const Vector &normal, const Vector &reflectDir, Scene &scene);
	Color getReflectionColor(Thing *thing, const Vector &pos, const Vector &normal, const Vector &reflectDir, Scene &scene, int depth);
	void render(int i, Scene &scene, int screenWidth, int screenHeight);
};
