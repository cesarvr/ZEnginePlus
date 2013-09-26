//
//  zeEscena.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeEscena__
#define __ZEnginePlus__zeEscena__

#include <iostream>
#include "zeManager.h"
#include "zeShader.h"
#include "zeRender.h"
#include "zeCamara.h"
#include "glm.hpp"
#include "transform.hpp"
#include "zeSkyBox.h"
#include "zeMapGenerator.h"
#include "zeVoxel.h"


#include <list>

class zeEscena{
private:
    const char *FICHERO_CONFIG = "/Users/cesarvr/Desktop/GameErr9E/Proyectos/ZEnginePlus/ZEnginePlus/config_file.cfg";
    zeConfiguracion configuracion;
    zeMappGenerator voxelMap;
    
    
public:
    
    zeEscena();
    
    void iniciar();
    void update(float delta);
    void render();
    
    void lookUp();
    void lookDown();
    void lookLeft();
    void lookRight();
    void irDerecha();
    void irIzquierda();
    void trackCursor(float x, float y);
};



#endif /* defined(__ZEnginePlus__zeEscena__) */
