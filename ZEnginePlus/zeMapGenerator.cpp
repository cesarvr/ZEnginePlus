//
//  zeMapGenerator.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 26/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeMapGenerator.h"

void zeMappGenerator::generarMapa(){

    
    terreno = zeTerreno();
    
    voxels.push_back(terreno);
    
}

std::vector<zeVoxel> zeMappGenerator::getVoxelMap(){ return voxels; }


void zeMappGenerator::drawMap(zeShader shader){

    for(zeVoxel &voxel : voxels) {
        voxel.prepararParaDibujar(shader);
    }

}

void zeMappGenerator::update(zeCamara camara){

    for(zeVoxel &voxel : voxels) {
        voxel.update(camara.proyeccion, camara.vista);
    }



}