//
//  zeBuffer.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeBuffer.h"



void zeBuffer::crearVertexBuffer(float *vertices, int size){
    
    
    std::cout << "sizeoffloat:" << sizeof(float)<< std::endl;
    int count = sizeof(vertices)/sizeof(float);
    std::cout << "sizeoffloat:" << count << std::endl;
    
    
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    

    
}


void zeBuffer::crearIndicesBuffer(short *indice, int size){

    
    cantidad_indices = size / sizeof(short);
    
    
    glGenBuffers(1, &indices_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indice, GL_STATIC_DRAW);

    
    


}