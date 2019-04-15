#ifndef PRIMITIVELISTH
#define PRIMITIVELISTH

#include "primitive.h"


//based on Shirley's model
class Primitive_list{
public:
	Primitive **list;
	int list_size;

	Primitive_list(){}
	Primitive_list(primitive **l, int n){
		list = l;
		list_size = n;
	}
	bool intersect(const ray& r, float t_min, float t_max, SurfaceInteraction& inter){
		SurfaceInteraction aux;
		bool hit_something = false;
		float closest_dist = t_max;
		for(int i = 0; i < list_size; i++){
			if (list[i]->hit(r,t_min,closest_dist, aux)){
				hit_something = true;
				closest_dist = aux.time;
				inter = aux;
			}
		}
		return hit_something;

	}

};




#endif