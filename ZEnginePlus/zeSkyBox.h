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
#include "zeSuperficieDib.h"

class zeSkyBox : public zeSuperficie {
    
    
public:
    
    void generarSkyBox(zeConfiguracion text);
    void setPosicion(float x, float y, float z);
    
};


#endif /* defined(__ZEnginePlus__zeSkyBox__) */
