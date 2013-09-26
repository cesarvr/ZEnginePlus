//
//  zeMapGenerator.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 26/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeMapGenerator__
#define __ZEnginePlus__zeMapGenerator__

#include <iostream>
#include <vector>
#include "zeVoxel.h"
#include "zeCamara.h"

class zeMappGenerator {
    zeTerreno terreno;
    std::vector <zeVoxel> voxels;
    
public:
    std::vector<zeVoxel> getVoxelMap();
    void    generarMapa ();
    void    drawMap     (zeShader shader);
    void    update      (zeCamara camara);
};


#endif /* defined(__ZEnginePlus__zeMapGenerator__) */
