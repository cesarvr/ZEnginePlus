//
//  zeMapp.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 15/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeMapp.h"


void zeMapp::inicio(zeTextura textura, zeCamara camara){

    string map = "000000000000000000000000000000000000000000000";
      map.append("000000000000000000000000000000000000000000000");
      map.append("00000000000000000XXXXXXXXX0000000000000000000");
      map.append("00000000000000000XXXXXXXXX0000000000000000000");
      map.append("00000000000000000XXXXXXXXX0000000000000000000");
      map.append("00000000000000000XXXXXXXXX0000000000000000000");
      map.append("000000000000000000000000000000000000000000000");
      map.append("000000000000000000000000000000000000000000000");
      map.append("000000000000000000000000000000000000000000000");
      
    float x =  0.0f;
    float y =  0.0f;
    float z = -3.0f;
    
    
    
    
    
    for (int i = 0; i < map.length(); i++) {
        
       char map_code =  map[i];
        
        
        if (map_code == '0') {
            zeTerreno terreno;
            terreno.crearTile(textura);
            terreno.setPosicion(x, y, z);
            
            terreno.tile.mvp = camara.proyeccion * camara.vista * terreno.tile.modelo;
            
            
            lista.push_back(terreno);
            
            x+=TERRENO_WIDHT;
        }
        
        if (map_code == '0') {
            x+=TERRENO_WIDHT;
        
        }
        
        if ((i % 5 && i>1) == 0) {
            z+= TERRENO_PROFUNDIDAD;
            x = 0.0f;
        }

        
    }
    
}