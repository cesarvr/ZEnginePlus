//
//  zeSuperficieDib.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 25/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeSuperficieDib.h"


zeSuperficie::zeSuperficie(): modelo(1.0f), mvp(1.0f)
{
    
    
    
}

void zeSuperficie::setAlto(float Alto) {


    HEIGHT = Alto;
}

void zeSuperficie::setAncho(float Ancho){

    WIDTH = Ancho;
}

void zeSuperficie::setTamanoZ(float Ztamano){

    ZSIZE = Ztamano;
    
}

void zeSuperficie::update(zeCamara camara){

    mvp = camara.proyeccion * camara.vista * modelo;
}


void zeSuperficie::prepararParaDibujar(zeShader shader){
    glUniformMatrix4fv(shader.getUniform("modelViewProjMatrix"), 1, GL_FALSE, &mvp[0][0]);
    

}

