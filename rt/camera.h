#pragma once

#include "vector.h"

class Camera
{
private:
	void Init();

public:

   	Vector forward;
	Vector right;
	Vector up;
	Vector pos;
	Vector lookAt;

	Camera();
	Camera(const Vector &p, const Vector &l);







};
