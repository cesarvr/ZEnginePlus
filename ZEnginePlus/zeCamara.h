//
//  zeCamara.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 15/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeCamara__
#define __ZEnginePlus__zeCamara__

#include <iostream>
#include "zeImport.h"

using glm::mat4;

class zeCamara{

#define CAMERASPEED	0.03f	
    mat4 desplazarCamara;
    
    
public:
    glm::vec3 mPos;
    glm::vec3 mView;
    glm::vec3 mUp;
    
    mat4 proyeccion, vista;
    zeCamara(glm::vec3 mPos, glm::vec3 mView, glm::vec3 mUp);
    void rotarCamara();
    
    /*void Posicion(float pos_x,  float pos_y,  float pos_z,
                  float view_x, float view_y, float view_z,
                  float up_x,   float up_y,   float up_z);
    
     */
    
    void update();
    void moverCamara(float speed);
    void rotarCamara(float speed);
    void rotarPosicionCamara(float speed);
    void desplazarIzquierda(float speed);
    void desplazarDerecha(float speed);
    void trackConCursor(float x, float y);
};




#endif /* defined(__ZEnginePlus__zeCamara__) */
