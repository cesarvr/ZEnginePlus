//
//  zeEscena.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeEscena.h"

zeConfiguracion configuracion;
zeTextura textura;
zeTerreno terreno;
zeShader shader;
zeRender dibujador;
zeCamara camara(glm::vec3(2,5,43),glm::vec3(0,0,0),glm::vec3(0,1,0));
zeMapp mapp;
zeSkyBox skyBox;

void zeEscena::iniciar(){

    
    configuracion.leerFicheroConfiguracion(FICHERO_CONFIG);
    textura.loadTextura(configuracion);
    
     
    shader.cargarShader("render_escena", configuracion.ruta);
    
    
    dibujador.setShader(shader);
    mapp.inicio(textura, camara);
    
    skyBox.generarSkyBox(textura);
 
    
    skyBox.tile.mvp = camara.proyeccion * camara.vista * skyBox.tile.modelo;
    
}



void zeEscena::render(){
    
    std::list<zeTerreno>::iterator voxel_it = mapp.lista.begin();
    
    dibujador.limpiar();
    
    while (voxel_it != mapp.lista.end()) {
       
        dibujador.draw(voxel_it->tile);
        voxel_it++;
    }
    
     //dibujador.draw(skyBox.tile);
    
    
    
    dibujador.volcarBuffer();
    
    
}


void zeEscena::update(float delta){
    
    
    
   // tile.modelo = glm::rotate(tile.modelo, 0.1f, glm::vec3(0.0f, 0.3f, 0.0f));
    
    
    camara.update();
    
    
    
    
    
    std::list<zeTerreno>::iterator voxel_it = mapp.lista.begin();
    
    
    while (voxel_it != mapp.lista.end()) {
       voxel_it->tile.mvp = camara.proyeccion * camara.vista * voxel_it->tile.modelo;
       
     //   voxel_it->tile.modelo = glm::rotate(voxel_it->tile.modelo, 0.1f, glm::vec3(0.0f, 0.3f, 0.0f));
        voxel_it++;
    }
    
    
   
    
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

