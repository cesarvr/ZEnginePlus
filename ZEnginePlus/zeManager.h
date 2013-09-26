//
//  zeManager.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 13/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeManager__
#define __ZEnginePlus__zeManager__
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "zeImport.h"
#include "zeGeometryDefinicion.h"
#include "lodepng.h"


using namespace std;





class zeTextura {
protected:
    
    map<string, string>regiones;
   
public:
    unsigned width, height;
    GLuint texturaId;
    void cargarTexturasGL(string pathFicheroImagen);
   
    
};


class zeConfiguracion {
private:
    zeTextura texturaObj;
    
    void        guardarArreglo(string line);
    void        cargarTextura(string pathFicheroTextura);
    textcoord   convertirATexturaCord(float * uv_coord);
    void        guardarColeccion(std::string line);
    
public:
    zeConfiguracion(string nombreFicheroConfiguracion);
    map <string, string> configuracion;
    string               nombreFicheroTextura;
    string               ruta;
    Region4              generarRegion4(std::vector<std::string> listaDeArreglos);
    
    void      leerFicheroConfiguracion(const char *nombreFichero);
    textcoord getRegion2DByNombre(string nombre);
    Region4   getRegion4ByNombre(string nombre);
    
   
};





#endif /* defined(__ZEnginePlus__zeManager__) */

