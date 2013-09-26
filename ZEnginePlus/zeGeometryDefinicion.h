//
//  zeGeometryDefinicion.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef ZEnginePlus_zeGeometryDefinicion_h
#define ZEnginePlus_zeGeometryDefinicion_h

union _uv_cordenadas{
    
    struct{
        
        float uvx1;
        float uvx2;
        float uvy1;
        float uvy2;
        
    };
};


typedef union _uv_cordenadas textcoord;


struct region_4_lados_t {
    textcoord izquierda;
    textcoord arriba;
    textcoord centro;
    textcoord abajo;
    textcoord derecha;
    textcoord atras;
};

typedef region_4_lados_t Region4;



#endif
