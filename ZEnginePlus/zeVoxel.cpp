//
//  zeVoxel.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 26/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeVoxel.h"

zeVoxel::zeVoxel():modelo(1.0f), mvp(1.0f){

    printf("iniciando zeVoxel");
}


void zeVoxel::prepararParaDibujar(zeShader shader){
   glUniformMatrix4fv(shader.getUniform("modelViewProjMatrix"), 1, GL_FALSE, &mvp[0][0]);
}


void zeVoxel::update(glm::mat4 proyeccion, glm::mat4 vista){
    mvp = proyeccion * vista * modelo;
}



zeTerreno::zeTerreno()
{

    
    float vertx1 = 0 + 0.5;
    float vertx2 = 0 - 0.5;
    float verty1 = 0 + 0.5;
    float verty2 = 0 - 0.5;
    
    float vertz1 =  0.5;
    float vertz2 = -0.5;
    
    
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
        vertx1, verty1, vertz1, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx2, verty1, vertz1, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx1, verty1, vertz2, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx2, verty1, vertz2, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        
        
        //front 4-7
        vertx1, verty1, vertz1, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx2, verty1, vertz1, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx1, verty2, vertz1, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx2, verty2, vertz1, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        
        //7-11
        vertx1, verty1, vertz2, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx2, verty1, vertz2, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx1, verty2, vertz2, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        vertx2, verty2, vertz2, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f,
        
    };
    
    short indices[]={0,1,2,3,4,5,6,7,10,11,8,9,9,4,4,6,8,10,10,5,5,7,9,11};

    buffer.crearIndicesBuffer( indices, sizeof( indices )  );
    buffer.crearVertexBuffer(  vertices, sizeof( vertices ) );
    
    
}