#include <iostream>
#include "ray.h"
#include "camera.h"
#include "surfaceInteraction.h"

using namespace std;
typedef vec3 Color;
typedef vec3 Point;


Camera::Camera(){}


Camera::Camera(Point origin_, Point vertical_, Point horizontal_,Point corner_){
	origin     = origin_;
	vertical   = vertical_;
	horizontal = horizontal_;
	corner = corner_;
}


bool Camera::hit_sphere(const Point& center, float radius, const ray& r){
	Point oc = r.origin() - center;
	float a = dot(r.direction(),r.direction());
	float b = 2.0 * dot(oc,r.direction());
	float c = dot(oc, oc) - radius*radius;

	float discriminant = b*b - 4*a*c;
	return (discriminant > 0);
}


Color Camera::fadeBG(const ray& r){
	//vetor unitario
	vec3 unit_direction = unit_vector(r.direction());

	//metade do Y do vetor unitário + 1 
	float t = 0.5*(unit_direction.y() + 1.0);

	//aumenta e diminui em funcao deste valor do (branco total ao azul)
	return (1.0-t)*Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
}


Color Camera::sample(const ray& r){
	if(hit_sphere(vec3(0,0,-1),0.5,r)){
		return vec3(1,0,0);
	}

	return fadeBG(r);
}


ray Camera::perspectiveRay(float x, float y){
	Point direction = corner + x*horizontal + y*vertical;

	ray generated(origin, direction);

	return generated;
}


ray Camera::orthogonalRay(float x, float y){
	Point origin = corner + x*horizontal + y*vertical;

	Point direction = origin;
	direction[2]  = (-1)*corner.z();

	ray generated(origin, direction);

	return generated;
}