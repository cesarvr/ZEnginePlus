//
//  zeBuffer.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeBuffer__
#define __ZEnginePlus__zeBuffer__

#include <iostream>
#include "zeImport.h"

#define SHORT_SIZE sizeof(short)


static const int POSITION_DATA_SIZE_IN_ELEMENTS = 3;
static const int COLOR_DATA_SIZE_IN_ELEMENTS = 3;
static const int TEXTURA_CORD_DATA_SIZE_IN_ELEMENTS = 2;
static const int SIZE_FLOAT_DATA = sizeof(float);

static const int bytes_bloques = (POSITION_DATA_SIZE_IN_ELEMENTS + COLOR_DATA_SIZE_IN_ELEMENTS + TEXTURA_CORD_DATA_SIZE_IN_ELEMENTS) * SIZE_FLOAT_DATA;


class zeBuffer {
    

    
public:
    GLuint vertex_buffer, indices_buffer;
    void crearVertexBuffer(float *vertices, int size);
    void crearIndicesBuffer(short *indices, int size);
    int cantidad_indices;
};

#endif /* defined(__ZEnginePlus__zeBuffer__) */
