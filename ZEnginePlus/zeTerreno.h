//
//  zeTerreno.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 14/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeTerreno__
#define __ZEnginePlus__zeTerreno__

#include <iostream>
#include "zeTile.h"


#define TERRENO_WIDHT 4.0f;
#define TERRENO_HEIGHT 1.0f;
#define TERRENO_PROFUNDIDAD 1.0f;

class zeTerreno{
    glm::vec3 posicion;
    
    
public:
    
    zeTile tile;
    void crearTile(zeTextura text);
    void setPosicion(float x, float y, float z);
};



#endif /* defined(__ZEnginePlus__zeTerreno__) */
