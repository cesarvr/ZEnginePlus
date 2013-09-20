//
//  zeMapp.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 15/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeMapp__
#define __ZEnginePlus__zeMapp__

#include <iostream>
#include <list>
#include "zeImport.h"
#include "zeTerreno.h"
#include "zeCamara.h"

class zeMapp {
    
    
public:
    void inicio(zeTextura textura, zeCamara camara);
    std::list<zeTerreno> lista;
};



#endif /* defined(__ZEnginePlus__zeMapp__) */
