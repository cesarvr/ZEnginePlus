//
//  zeEscena.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeEscena.h"


zeTextura textura;

zeShader shader;
zeRender dibujador;
zeCamara camara(glm::vec3(2,5,23),glm::vec3(0,0,0),glm::vec3(0,1,0));

zeSkyBox skyBox;


zeEscena::zeEscena():configuracion(FICHERO_CONFIG){


}

void zeEscena::iniciar(){

    

    
    shader.cargarShader("render_escena", configuracion.nombreFicheroTextura);
    
    dibujador.setShader(shader);
    //mapp.inicio(textura, camara);
    
    skyBox.generarSkyBox(configuracion);
 
    voxelMap.generarMapa();
    //skyBox.tile.mvp = camara.proyeccion * camara.vista * skyBox.tile.modelo;
    
}



void zeEscena::render(){
    
    //std::list<zeTerreno>::iterator voxel_it = mapp.lista.begin();
    
    dibujador.limpiar();
    
    
    /*
    while (voxel_it != mapp.lista.end()) {
       
        dibujador.draw(voxel_it->tile);
        voxel_it++;
    }*/
    
     skyBox.prepararParaDibujar(shader);
     dibujador.draw(skyBox);
     
    
    voxelMap.drawMap(shader);
    

    for (zeVoxel &voxel : voxelMap.getVoxelMap()) {
        dibujador.draw(voxel);
    }
    
    
    

    
}


void zeEscena::update(float delta){
    
    
    
   // tile.modelo = glm::rotate(tile.modelo, 0.1f, glm::vec3(0.0f, 0.3f, 0.0f));
    
    
    camara.update();
    
    
    
    //skyBox.tile.mvp = camara.proyeccion * camara.vista * skyBox.tile.modelo;
    
    
    
    
    //std::list<zeTerreno>::iterator voxel_it = mapp.lista.begin();
    
    /*
    while (voxel_it != mapp.lista.end()) {
       voxel_it->tile.mvp = camara.proyeccion * camara.vista * voxel_it->tile.modelo;
       
     //   voxel_it->tile.modelo = glm::rotate(voxel_it->tile.modelo, 0.1f, glm::vec3(0.0f, 0.3f, 0.0f));
        voxel_it++;
    }*/
    
    
    skyBox.update(camara);
    
    voxelMap.update(camara);
    
}

void zeEscena::lookUp(){

    camara.moverCamara(CAMERASPEED);
}

void zeEscena::lookDown(){
    camara.moverCamara(-CAMERASPEED);


}


void zeEscena::lookRight(){

    camara.rotarCamara(CAMERASPEED);

}

void zeEscena::lookLeft(){
    camara.rotarCamara(-CAMERASPEED);
}


void zeEscena::irDerecha(){

    camara.desplazarDerecha(-CAMERASPEED);
}

void zeEscena::irIzquierda(){
    camara.desplazarIzquierda(CAMERASPEED);
}

void zeEscena::trackCursor(float x, float y){
    
    camara.trackConCursor(x, y);

}

