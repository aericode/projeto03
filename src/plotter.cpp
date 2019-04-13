#include <iostream>
#include <fstream>

#include "vec3.h"
#include "plotter.h"

#include <vector>
#include <string>

using namespace std;
typedef vec3 Color;

Plotter::Plotter(){}

Plotter::Plotter(int xSize_,int ySize_,std::string fileName_){

	fileName = fileName_;

	xSize = xSize_;
	ySize = ySize_;

	fileLineCount = (xSize*ySize) + 3;

	pixelColor = new Color[fileLineCount];

	clear();

	plotFile();
}

Plotter::~Plotter(){
	delete[] pixelColor;
}

int Plotter::matrixToLine(int x, int y){
	return x + ( (ySize-1)-y)*xSize;
}

bool Plotter::isValidLocation(int x, int y){
	bool validX = (x < xSize) && (x >= 0);
	bool validY = (y < ySize) && (y >= 0);

	return validX && validY;
}

void Plotter::changePixel(int x, int y, Color color = Color(0,0,0)){
	//se estiver fora do limite simplesmente ignora
	if(!isValidLocation(x,y)){return;}

	int indexLine = 3 + matrixToLine(x,y);
	pixelColor[indexLine] = color;
}

void Plotter::clear(){
	for(int i = 3;i < fileLineCount;i++){
		pixelColor[i]= Color(255,255,255);
	}
}


void Plotter::plotFile(){
	std::ofstream myfile;

	myfile.open(fileName.c_str());



	myfile<< "P3" <<std::endl;
	myfile<< std::to_string(xSize) + " " +  std::to_string(ySize) <<std::endl;
	myfile<< "255" <<std::endl;


	for(int i = 4;i < fileLineCount;i++){
		myfile<<pixelColor[i]<<std::endl;
	}
}