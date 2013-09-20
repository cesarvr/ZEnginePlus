//
//  zeTile.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 13/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeTile__
#define __ZEnginePlus__zeTile__

#include <iostream>
#include "zeGeometryDefinicion.h"
#include "zeBuffer.h"
#include "zeImport.h"
#include "zeManager.h"

using glm::vec4;
using glm::mat4;





class zeTile {
  
    
public:
    zeTile(){};
    zeTile(zeTextura ztext);
    mat4 mvp, modelo;
    vec4 dimensiones;
    zeTextura textura;
    zeBuffer vertexBuffer;
    

};


#endif /* defined(__ZEnginePlus__zeTile__) */
