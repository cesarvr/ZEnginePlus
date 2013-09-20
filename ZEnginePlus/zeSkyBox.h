//
//  zeSkyBox.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 16/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeSkyBox__
#define __ZEnginePlus__zeSkyBox__

#include <iostream>
#include "zeTile.h"


class zeSkyBox {
    const float WIDTH  = 40.0f;
    const float HEIGHT = 40.0f;
    const float ZSIZE  = 40.0f;
    
public:
    zeTile tile;
    void generarSkyBox(zeTextura text);
    void setPosicion(float x, float y, float z);
    
};


#endif /* defined(__ZEnginePlus__zeSkyBox__) */
