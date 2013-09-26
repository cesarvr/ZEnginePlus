//
//  zeSkyBox.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 16/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeSkyBox.h"



void zeSkyBox::generarSkyBox(zeConfiguracion text){


    setTamanoZ(40.0f);
    setAncho(40.0f);
    setAlto(40.0f);
    
    
    Region4 cubeMap = text.getRegion4ByNombre("sky_space");
    

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
        
        
        //top 0,0,1,2,3,3
        vertx1, verty1, vertz2, 0.7f, 0.7f, 0.4f, cubeMap.arriba.uvx1, cubeMap.arriba.uvy1,
        vertx2, verty1, vertz2, 0.7f, 0.7f, 0.4f, cubeMap.arriba.uvx2, cubeMap.arriba.uvy1,
        vertx1, verty1, vertz1, 0.7f, 0.7f, 0.4f, cubeMap.arriba.uvx1, cubeMap.arriba.uvy2,
        vertx2, verty1, vertz1, 0.7f, 0.7f, 0.4f, cubeMap.arriba.uvx2, cubeMap.arriba.uvy2,
        
        
        //front 4-7
        vertx1, verty1, vertz1, 0.7f, 0.4f, 0.4f, cubeMap.centro.uvx1, cubeMap.centro.uvy1,
        vertx2, verty1, vertz1, 0.7f, 0.4f, 0.4f, cubeMap.centro.uvx2, cubeMap.centro.uvy1,
        vertx1, verty2, vertz1, 0.7f, 0.4f, 0.4f, cubeMap.centro.uvx1, cubeMap.centro.uvy2,
        vertx2, verty2, vertz1, 0.7f, 0.4f, 0.4f, cubeMap.centro.uvx2, cubeMap.centro.uvy2,
        
        //Atras 8,8,9,10,11,11
        vertx1, verty1, vertz2, 0.7f, 0.4f, 0.9f, cubeMap.atras.uvx2, cubeMap.atras.uvy1,
        vertx2, verty1, vertz2, 0.7f, 0.4f, 0.9f, cubeMap.atras.uvx1, cubeMap.atras.uvy1,
        vertx1, verty2, vertz2, 0.7f, 0.4f, 0.9f, cubeMap.atras.uvx2, cubeMap.atras.uvy2,
        vertx2, verty2, vertz2, 0.7f, 0.4f, 0.9f, cubeMap.atras.uvx1, cubeMap.atras.uvy2,
        
        /*abajo  12, 13,14,15  */
        vertx1, verty2, vertz2, 0.2f, 0.4f, 0.4f, cubeMap.abajo.uvx1, cubeMap.abajo.uvy1,
        vertx2, verty2, vertz2, 0.2f, 0.4f, 0.4f, cubeMap.abajo.uvx2, cubeMap.abajo.uvy1,
        vertx1, verty2, vertz1, 0.2f, 0.4f, 0.4f, cubeMap.abajo.uvx1, cubeMap.abajo.uvy2,
        vertx2, verty2, vertz1, 0.2f, 0.4f, 0.4f, cubeMap.abajo.uvx2, cubeMap.abajo.uvy2,
      
        /*derecha  16,16,17,18,19 */
        vertx2, verty1, vertz1, 0.2f, 0.4f, 0.1f, cubeMap.derecha.uvx1, cubeMap.derecha.uvy1,
        vertx2, verty1, vertz2, 0.2f, 0.4f, 0.5f, cubeMap.derecha.uvx2, cubeMap.derecha.uvy1,
        vertx2, verty2, vertz1, 0.2f, 0.4f, 0.5f, cubeMap.derecha.uvx1, cubeMap.derecha.uvy2,
        vertx2, verty2, vertz2, 0.2f, 0.4f, 0.1f, cubeMap.derecha.uvx2, cubeMap.derecha.uvy2,
    

        /*izquierda  20,20,21,22,23,23 */
        vertx1, verty1, vertz2, 0.9f, 0.2f, 0.1f, cubeMap.izquierda.uvx1, cubeMap.izquierda.uvy1,
        vertx1, verty1, vertz1, 0.9f, 0.2f, 0.5f, cubeMap.izquierda.uvx2, cubeMap.izquierda.uvy1,
        vertx1, verty2, vertz2, 0.9f, 0.2f, 0.5f, cubeMap.izquierda.uvx1, cubeMap.izquierda.uvy2,
        vertx1, verty2, vertz1, 0.9f, 0.2f, 0.1f, cubeMap.izquierda.uvx2, cubeMap.izquierda.uvy2,
    
        
        
    };
    
    //0,1,2,3,3,4,4,5,6,7,7,16,16,17,18,19,19,20,20,21,22,23,23,12,12,13,14,15,15, 8,8,9,10,11,11
    
    short indices[]={0,1,2,3,3,4,4,5,6,7,7,16,16,17,18,19,19,20,20,21,22,23,23,12,12,13,14,15,15, 8,8,9,10,11,11};
    
    buffer.crearIndicesBuffer( indices, sizeof( indices )  );
    buffer.crearVertexBuffer(  vertices, sizeof( vertices ) );
    


}