#pragma once

#include <list>
	using std::list;

#include "scene.h"
#include "thing.h"
#include "light.h"
#include "camera.h"

class Scene
{
public:
	list<Thing *> things;
	list<Light *> lights;
	Camera camera;
	

};

