#include <iostream>
#include <fstream>

#include "json.hpp"
#include "jsonReader.h"
#include "camera.h"
#include "ray.h"
#include "plotter.h"

using json::JSON;
typedef vec3 Color;

int main(){

	JSON obj = parseFile("./jsonInput/scene.json");
	Camera cam = cameraFromJSON(obj);


	int nx = 200;
	int ny = 100;

	Plotter orthogonal(nx,ny,"./imageOutput/ortogonal.ppm");
	Plotter perspective(nx,ny,"./imageOutput/perspective.ppm");


	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);

			ray rOrth  = cam.orthogonalRay(u,v); 
			ray rPers  = cam.perspectiveRay(u,v);

			//COL recebe um raio ortgonal
			vec3 col = cam.sample(rOrth);

			int ir  = int(255.99*col[0]);
			int ig  = int(255.99*col[1]);
			int ib  = int(255.99*col[2]);

			orthogonal.changePixel(i,j, Color(ir,ig,ib));

			//COL recebe um raio em perspectiva 
			col = cam.sample(rPers);

			ir  = int(255.99*col[0]);
			ig  = int(255.99*col[1]);
			ib  = int(255.99*col[2]);

			perspective.changePixel(i,j, Color(ir,ig,ib));
		}
	}

	orthogonal.plotFile();
	perspective.plotFile();
	

}