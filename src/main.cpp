#include <iostream>
#include <fstream>

#include "json.hpp"
#include "jsonReader.h"
#include "camera.h"
#include "ray.h"
#include "sphere.h"
#include "plotter.h"



using json::JSON;
typedef vec3 Color;
typedef vec3 Point;

int main(){

	JSON obj = parseFile("./jsonInput/scene.json");
	Camera cam = cameraFromJSON(obj);


	int nx = 200;
	int ny = 100;

	Plotter perspective(nx,ny,"./imageOutput/perspective.ppm");

	Primitive *list[5];
	list[0] = new Sphere(Point(1,0,-1), 0.5);
	list[1] = new Sphere(Point(0,0,-1), 0.5);
	list[2] = new Sphere(Point(-1,0,-1), 0.5);
	list[3] = new Sphere(Point(0,1,-1), 0.5);
	list[4] = new Sphere(Point(0,-1,-1), 0.5);

	Primitive_list *world = new Primitive_list(list,5); 

	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);

			ray r = cam.perspectiveRay(u,v);

			//COL recebe um raio ortgonal
			vec3 col = cam.sample(r, world);

			int ir  = int(255.99*col[0]);
			int ig  = int(255.99*col[1]);
			int ib  = int(255.99*col[2]);

			perspective.changePixel(i,j, Color(ir,ig,ib));
		}
	}

	perspective.plotFile();
	

}