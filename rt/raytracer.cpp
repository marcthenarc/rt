#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "raytracer.h"

Raytracer::Raytracer()
{

}

Intersection Raytracer::intersections(const Ray &ray, Scene &scene)
{
	Intersection closestInter;

	list<Thing *>::iterator it = scene.things.begin(), end = scene.things.end();

	int count = 0;

	for (; it != end; it++)
	{
		double dist;

		if ((*it)->Intersect(ray, dist))
		{
			if (closestInter.thing == NULL || dist < closestInter.dist)
			{
				closestInter.thing = *it;
				closestInter.ray = ray;
				closestInter.dist = dist;
			}
		}

		count++;
	}

	return closestInter;
}

bool Raytracer::testRay(const Ray &ray, Scene &scene, double &dist)
{
	Intersection isect = intersections(ray, scene);

	if (isect.thing == NULL)
		return false;

	dist = isect.dist;
	return true;
}

Color Raytracer::traceRay(const Ray &ray, Scene &scene, int depth)
{
	Intersection isect = intersections(ray, scene);

	if (isect.thing == NULL)
		return Color::background;

	return shade(isect, scene, depth);
}

Color Raytracer::shade(Intersection &isect, Scene &scene, int depth)
{
	Vector d = isect.ray.dir;
	Vector pos = (d * isect.dist) + isect.ray.start;
	Vector normal = isect.thing->Normal(pos);
	Vector reflectDir = d - (normal * (Dot(normal, d)) * 2);
	Color naturalColor = Color::background + getNaturalColor(isect.thing, pos, normal, reflectDir, scene);
	Color reflectedColor = (depth >= maxDepth) ? Color::grey : getReflectionColor(isect.thing, pos, normal, reflectDir, scene, depth);
    return (naturalColor + reflectedColor);
}

Color Raytracer::getNaturalColor(Thing *thing, const Vector &pos, const Vector &normal, const Vector &reflectDir, Scene &scene)
{
	Color ret;

	list<Light *>::iterator it = scene.lights.begin(), end = scene.lights.end();

	for (; it != end; it++)
	{
		Vector ldis = (*it)->pos - pos;
		Vector livec = ldis.GetNorm();

		double dist;
		Ray ray(pos, livec);
		bool isInShadow = (testRay(ray, scene, dist) == false) ? false : dist <= ldis.Mag();

		if (isInShadow)
			ret += Color::defaultColor;
		else
		{
			double illum = Dot(livec, normal);
			Color lcolor = (illum > 0) ? ((*it)->color * illum) : Color::defaultColor;

			// Pourquoi le const s'applique à GetNorm() ?
			Vector d = reflectDir;
			double specular = Dot(livec, d.GetNorm());
			Color scolor = (specular > 0) ? (*it)->color * pow(specular, thing->surface->roughness) : Color::defaultColor;

			Color diff = thing->surface->diffuse(pos) * lcolor;
			Color spec = thing->surface->specular(pos) * scolor;

			ret += diff + spec;
		}
	}

	return ret;
}

Color Raytracer::getReflectionColor(Thing *thing, const Vector &pos, const Vector &normal, const Vector &reflectDir, Scene &scene, int depth)
{
	Ray ray(pos, reflectDir);
	return traceRay(ray, scene, depth + 1) * thing->surface->reflect(pos);
}

void Raytracer::render(int i, Scene &scene, int screenWidth, int screenHeight)
{
	unsigned char wh = (unsigned char)(screenWidth >> 8);
	unsigned char hh = (unsigned char)(screenHeight >> 8);

	unsigned char header[18] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		(unsigned char)(screenWidth - (wh << 8)), wh,
		(unsigned char)(screenHeight - (hh << 8)), hh,
		24, 0x20
	};

	char fn[30];
	sprintf(fn, "test%03d.tga", i);
	FILE *fp = fopen(fn, "wb");

	fwrite(header, 18, 1, fp);

	double keep = 0;

	for (int y=0; y<screenHeight; y++)
	{
		printf("%d\n", y);

		for (int x = 0; x < screenWidth; x++)
		{
			double recenterY = - (y - (screenHeight / 2.0)) / screenHeight;
			double recenterX = (x - (screenWidth / 2.0)) / screenWidth;

			Vector dir = ( scene.camera.forward + ((scene.camera.right * recenterX) + (scene.camera.up * recenterY) ) ).GetNorm();

/*
			if (y == 400)
			{
				double angle = 90 - acos(dir.x) * 180 / M_PI;
				printf("%f => ", dir.Mag());
				printf("%f : (%f) ", angle, (keep == 0) ? 0 : keep - angle);
				keep = angle;
				dir.Print();
			}
*/
			Ray ray(scene.camera.pos, dir);
			Color color = traceRay(ray, scene, 0);

			unsigned char comp[3];
			color.GetBGRComponents(comp);
            fwrite(comp, 3, 1, fp);

		}
	}

	fclose(fp);
}
