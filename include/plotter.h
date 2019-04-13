#ifndef PLOTTER
#define PLOTTER
#include <iostream>
#include <fstream>

#include "vec3.h"

#include <vector>
#include <string>

using namespace std;
typedef vec3 Color;

class Plotter
{
private:

	int xSize;
	int ySize;
    std::string  fileName;
    int fileLineCount;
    Color* pixelColor;

public:
	Plotter();

	Plotter(int,int,string);

	~Plotter();

	int matrixToLine(int, int);

	bool isValidLocation(int, int);

	void changePixel(int, int, Color);

	void clear();
	
	void plotFile();
};

#endif