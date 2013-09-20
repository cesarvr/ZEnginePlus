//
//  ZEEscenaPrueba1.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 20/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "ZEEscenaPrueba1.h"

uint vertBuffer, vertIndices;
int cantidad_indices;
zeShader zombiShader;
GLuint shdColor, shdTexturaCord,shdPosicion;
GLuint shoffset, shzNear,shzFar, shfrustumScale;


void EscenaUno::iniciar(){

    
    zeConfiguracion configuracion;
    
    configuracion.leerFicheroConfiguracion("/Users/cesarvr/Desktop/GameErr9E/Proyectos/ZEnginePlus/ZEnginePlus/config_file.cfg");

    // shaders
    zombiShader.cargarShader("perspectiva", configuracion.ruta);
    
   //GLuint shdMvp         = zombiShader.getUniform("modelViewProjMatrix");
    shdColor       = zombiShader.getParametros("color");        // :@"color"];
    shdTexturaCord = zombiShader.getParametros("textura_cord"); // :@"textura_cord"];
    shdPosicion    = zombiShader.getParametros("position");     // :@"position"];
 //  GLuint texturaID      = zombiShader.getUniform("textura");   //(programID, "myTextureSampler");

    
    shoffset = zombiShader.getParametros("offset");
    shzNear = zombiShader.getParametros("zNear");
    shzFar = zombiShader.getParametros("zFar");
    shfrustumScale = zombiShader.getParametros("frustumScale");
    
    float x_size = 4.0f / 2.0f;
    float vertx1 = 0 + x_size;
    float vertx2 = 0 - x_size;
    float verty1 = 0 + 1.0f;
    float verty2 = 0 - 1.0f;
    
    float vertz1 =  1.0f;
    float vertz2 = -1.0f;
    
    
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
        vertx1, verty1, vertz1, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx2, verty1, vertz1, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx1, verty1, vertz2, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx2, verty1, vertz2, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        
        
        //front 4-7
        vertx1, verty1, vertz1, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx2, verty1, vertz1, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx1, verty2, vertz1, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx2, verty2, vertz1, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        
        //7-11
        vertx1, verty1, vertz2, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx2, verty1, vertz2, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx1, verty2, vertz2, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        vertx2, verty2, vertz2, 0.7f, 0.4f, 0.4f, 0.0f, 0.0f,
        
        
        
        
    };
    
    
    short indices[]={0,1,2,3,4,5,6,7,10,11,8,9,9,4,4,6,8,10,10,5,5,7,9,11};
    
    
    cantidad_indices = sizeof(indices) / sizeof(short);
    
    
    glGenBuffers(1, &vertIndices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertIndices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    
    std::cout << "sizeoffloat:" << sizeof(float)<< std::endl;
    int count = sizeof(vertices)/sizeof(float);
    std::cout << "sizeoffloat:" << count << std::endl;
    
    
    glGenBuffers(1, &vertBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    
    
    /*
      ==== ==== ==== ==== ==== ====
     
     
     Load data to GPU RAM
     
      ==== ==== ==== ==== ==== ====
     
     */
    
    glBindBuffer(GL_ARRAY_BUFFER, vertBuffer);
    
    glVertexAttribPointer(shdPosicion,
                          POSITION_DATA_SIZE_IN_ELEMENTS,
                          GL_FLOAT,
                          false,
                          bytes_bloques,
                          (void *)0);
    
    
    glEnableVertexAttribArray(shdPosicion);
    
    
    /**
     COLOR**/
    
    glVertexAttribPointer(shdColor,
                          COLOR_DATA_SIZE_IN_ELEMENTS,
                          GL_FLOAT,
                          false,
                          bytes_bloques,
                          (void *)(POSITION_DATA_SIZE_IN_ELEMENTS * SIZE_FLOAT_DATA));
    
    glEnableVertexAttribArray(shdColor);
    
    
    
    glVertexAttribPointer(shdTexturaCord,
                          TEXTURA_CORD_DATA_SIZE_IN_ELEMENTS,
                          GL_FLOAT,
                          false,
                          bytes_bloques,
                          (void *)((POSITION_DATA_SIZE_IN_ELEMENTS+COLOR_DATA_SIZE_IN_ELEMENTS) * SIZE_FLOAT_DATA));
    
    
    
    /**/
    
    
}




EscenaUno::render(){




}




