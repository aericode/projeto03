#include "json.hpp"
#include <iostream>
#include <cstddef>
#include <algorithm>
#include <fstream>
#include <string>


#include "vec3.h"
#include "camera.h"


using json::JSON;
using namespace std;

typedef vec3 Color;

string stringFromFile(string filename)
{
    //pega o arquivo e transforma em uma string pronta para ser convertida em objeto
    string aux;
    string userInput;
    ifstream infile;
    infile.open (filename);
        while(!infile.eof()){
            getline(infile,aux);
            userInput += aux;
        }
    infile.close();

    return userInput;
}

JSON parseFile(string filename){
    JSON obj;
    string userInput = stringFromFile(filename);
    obj = JSON::Load(userInput);
    return obj;
}

Camera cameraFromJSON(JSON obj){
    if (obj["camera"].IsNull()){
        std::cout<<"no instructions for camera in JSON file"<<std::endl;
        return Camera();
    }else{
        string camParts[4] = {"origin","vertical","horizontal","corner"};
        vec3 aux[4];

        for(int i = 0; i < 4; i++){
            for(int j = 0;j < 3;j++){
                aux[i][j] = obj["camera"][camParts[i]][j].ToFloat();
            }
        }

        return Camera(aux[0],aux[1],aux[2],aux[3]);
    }
}