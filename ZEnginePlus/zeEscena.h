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
#include "zeTerreno.h"
#include "zeShader.h"
#include "zeRender.h"
#include "zeCamara.h"
#include "zeMapp.h"
#include "glm.hpp"
#include "transform.hpp"
#include "zeSkyBox.h"
#include <list>

class zeEscena{
private:
    const char *FICHERO_CONFIG = "/Users/cesarvr/Desktop/GameErr9E/Proyectos/ZEnginePlus/ZEnginePlus/config_file.cfg";

public:
    
    void iniciar();
    void update(float delta);
    void render();
    
    void lookUp();
    void lookDown();
    void lookLeft();
    void lookRight();
    void irDerecha();
    void irIzquierda();
    
};



#endif /* defined(__ZEnginePlus__zeEscena__) */
