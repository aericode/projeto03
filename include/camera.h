#ifndef CAMERAH
#define CAMERAH

#include <iostream>
#include "ray.h"

using namespace std;
typedef vec3 Color;
typedef vec3 Point;

class Camera{
private:
	vec3 origin;
	vec3 vertical;
	vec3 horizontal;
	vec3 corner;

public:
	Camera();

	Camera(Point, Point, Point, Point);

	bool hit_sphere(const Point&, float, const ray&);

	Color fadeBG(const ray&);

	Color sample(const ray&);

	ray perspectiveRay(float, float);

	ray orthogonalRay(float, float);
};

#endif