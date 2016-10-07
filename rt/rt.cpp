#include <iostream>
	using std::cout;
	using std::endl;

#include <cstdlib>

#include "vector.h"
#include "ray.h"
#include "scene.h"
#include "raytracer.h"
#include "plane.h"
#include "sphere.h"

void defaultScene(Scene &scene, double back)
{
	scene.things.push_back(new Plane(Vector(0.0, 1.0, 0.0), 0.0, new CheckerboardSurface()));
	scene.things.push_back(new Sphere(Vector(0.0, 1.0, -0.25), 1.0, new ShinySurface()));
	scene.things.push_back(new Sphere(Vector(-1.0, 0.5, 1.5), 0.5, new ShinySurface()));

	scene.lights.push_back(new Light(Vector(-2.0, 2.5, 0.0), Color(0.49, 0.07, 0.07)));
	scene.lights.push_back(new Light(Vector(1.5, 2.5, 1.5), Color(0.07, 0.07, 0.49)));
	scene.lights.push_back(new Light(Vector(1.5, 2.5, -1.5), Color(0.07, 0.49, 0.071)));
	scene.lights.push_back(new Light(Vector(0.0, 3.5, 0.0), Color(0.21, 0.21, 0.35)));

	scene.camera = Camera(Vector(3.0, 2.0, 4.0 - back), Vector(-1.0, 0.5, 0.0));
//	scene.camera = Camera(Vector(0,0,0), Vector(0, 0, 1));
}

int main(int argc, char **argv)
{
	int max = 1;

	if (argc > 1)
		max = atoi(argv[1]);

	for (int i=0; i<max; i++)
	{
		try
		{
			Scene scene;
			defaultScene(scene, 0.1 * (double)i);

			Raytracer rt;
			rt.render(i, scene, 800, 800);
		}
		catch (const char *e)
		{
			cout << e << endl;
			return 1;
		}
	}

	return 0;
}
