//
//  zeVoxel.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 26/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeVoxel__
#define __ZEnginePlus__zeVoxel__

#include <iostream>

#include "zeBuffer.h"
#include "zeImport.h"
#include "zeShader.h"


class zeVoxel {
    
    
public:
    
    glm::mat4 modelo, mvp;
    
public:
    zeBuffer buffer;
    
    zeVoxel();
    void update(glm::mat4 proyeccion, glm::mat4 vista);
    void prepararParaDibujar( zeShader shader );
    void limpiar();


};


class zeTerreno: public zeVoxel {

public:
    zeTerreno();


};




#endif /* defined(__ZEnginePlus__zeVoxel__) */
