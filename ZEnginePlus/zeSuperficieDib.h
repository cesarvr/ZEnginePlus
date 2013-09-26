//
//  zeSuperficieDib.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 25/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeSuperficieDib__
#define __ZEnginePlus__zeSuperficieDib__

#include <iostream>
#include "zeManager.h"
#include "zeBuffer.h"
#include "zeImport.h"
#include "zeShader.h"
#include "zeCamara.h"


class zeSuperficie {
protected:
     float WIDTH;
     float HEIGHT;
     float ZSIZE;
     glm::mat4 mvp, modelo;
    
public:
    
    
    zeBuffer buffer;
    zeSuperficie();

    void    setAncho               (float Ancho);
    void    setAlto                (float Alto);
    void    setTamanoZ             (float Ztamano);
    void    generarSkyBox          (zeConfiguracion text);
    void    setPosicion            (float x, float y, float z);
    void    update                 (zeCamara camara);
    void    prepararParaDibujar    (zeShader shader);
};


#endif /* defined(__ZEnginePlus__zeSuperficieDib__) */
