//
//  zeSkyBox.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 16/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeSkyBox.h"



void zeSkyBox::generarSkyBox(zeTextura text){


    tile = zeTile(text);
    
    
    textcoord coord = text.getRegionByNombre("terreno_top");
    textcoord face  = text.getRegionByNombre("terreno_face");
    
    

    float vertx1 = 0 + WIDTH;
    float vertx2 = 0 - WIDTH;
    float verty1 = 0 + HEIGHT;
    float verty2 = 0 - HEIGHT;
    
    float vertz1 =  ZSIZE;
    float vertz2 = -ZSIZE;
    
    
    float vertices[]= {
        
        /*
         4   +x     +y   +z
         5   -x     +y   +z
         6   +x     -y   +z
         7   -x     -y   +z
         
         8   +x     +y   -z
         9   -x     +y   -z
         10  +x     -y   -z
         11  -x     -y   -z
         
         
         */
        
        
        //top 0-3
        vertx1, verty1, vertz1, 0.7f, 0.4f, 0.4f, coord.uvx1, coord.uvy1,
        vertx2, verty1, vertz1, 0.7f, 0.4f, 0.4f, coord.uvx2, coord.uvy1,
        vertx1, verty1, vertz2, 0.7f, 0.4f, 0.4f, coord.uvx1, coord.uvy2,
        vertx2, verty1, vertz2, 0.7f, 0.4f, 0.4f, coord.uvx2, coord.uvy2,
        
        
        //front 4-7
        vertx1, verty1, vertz1, 0.7f, 0.4f, 0.4f, face.uvx1, face.uvy1,
        vertx2, verty1, vertz1, 0.7f, 0.4f, 0.4f, face.uvx2, face.uvy1,
        vertx1, verty2, vertz1, 0.7f, 0.4f, 0.4f, face.uvx1, face.uvy2,
        vertx2, verty2, vertz1, 0.7f, 0.4f, 0.4f, face.uvx2, face.uvy2,
        
        //7-11
        vertx1, verty1, vertz2, 0.7f, 0.4f, 0.4f, face.uvx1, face.uvy1,
        vertx2, verty1, vertz2, 0.7f, 0.4f, 0.4f, face.uvx2, face.uvy1,
        vertx1, verty2, vertz2, 0.7f, 0.4f, 0.4f, face.uvx1, face.uvy2,
        vertx2, verty2, vertz2, 0.7f, 0.4f, 0.4f, face.uvx2, face.uvy2,
        
        
        
        
    };
    
    
    short indices[]={0,1,2,3,4,5,6,7,10,11,8,9,9,4,4,6,8,10,10,5,5,7,9,11};
    
    tile.vertexBuffer.crearIndicesBuffer( indices, sizeof( indices )  );
    tile.vertexBuffer.crearVertexBuffer( vertices, sizeof( vertices ) );
    


}