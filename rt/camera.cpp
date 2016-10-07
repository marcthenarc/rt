#include "camera.h"

Camera::Camera() : lookAt(0,0,1)
{
	Init();	
}

Camera::Camera(const Vector &p, const Vector &l) : pos(p), lookAt(l)
{
	Init();
}

void Camera::Init()
{
	Vector down(0.0, -1.0, 0.0);
	
   	forward = (lookAt - pos).GetNorm();
	right = (Cross(forward, down)).GetNorm() * 0.75;

	up = (Cross(forward, right)).GetNorm() * 0.75;
}
