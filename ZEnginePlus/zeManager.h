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

class zeConfiguracion {
    
    
public:
    map <string, string> configuracion;
    string nombreFicheroTextura;
    string ruta;
    void leerFicheroConfiguracion(const char *nombreFichero);
   
};



class zeTextura {
protected:
 
    map<string, string>regiones;
    unsigned width, height;
public:
    GLuint texturaId;
    void loadTextura(zeConfiguracion config);
    textcoord getRegionByNombre(string nombre);
    
};


#endif /* defined(__ZEnginePlus__zeManager__) */

