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
	Plotter orthogonal(nx,ny,"./imageOutput/perspective.ppm");

	Primitive *list[2];
	list[0] = new Sphere(Point(0,0,-1), 0.5);
	//list[1] =

	Primitive_list *world = new Primitive_list(list,1); 

	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);

			ray rOrth  = cam.orthogonalRay(u,v); 
			ray rPers  = cam.perspectiveRay(u,v);

			//COL recebe um raio ortgonal
			vec3 col = cam.sample(rOrth,world);

			int ir  = int(255.99*col[0]);
			int ig  = int(255.99*col[1]);
			int ib  = int(255.99*col[2]);

			orthogonal.changePixel(i,j, Color(ir,ig,ib));

			//COL recebe um raio em perspectiva 
			col = cam.sample(rPers,world);

			ir  = int(255.99*col[0]);
			ig  = int(255.99*col[1]);
			ib  = int(255.99*col[2]);

			perspective.changePixel(i,j, Color(ir,ig,ib));
		}
	}

	orthogonal.plotFile();
	perspective.plotFile();
	

}