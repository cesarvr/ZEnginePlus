//
//  zeManager.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 13/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeManager.h"


void zeConfiguracion::leerFicheroConfiguracion(const char *nombreFichero){

    printf("[fichero de configuracion [cargando..]]");

    
    ifstream inFichero(nombreFichero);
    string line;

    bool comment = true;

    

    while(getline(inFichero, line)) {
        
        string key;
        string value;
        
        
        if (line.find("/*") != string::npos) {
            comment = true;
        }
        
        
        if (!comment) {
            size_t posicion_separador = line.find(":");
            
            if (posicion_separador != string::npos) {
                key = line.substr(0, posicion_separador);
                value = line.substr(posicion_separador + 1, (line.length() - posicion_separador));
              
                if ( key == "path" )
                    ruta = value;
                else if ( key == "texturas" )
                    nombreFicheroTextura = ruta+value;
                else
                    configuracion[key] = value;
                
            }
            
        }
        
        
        if(line.find("*/") != string::npos ){
            comment = false;
            
        }
        
    }
    
    inFichero.close();

    
}


void zeTextura::loadTextura(zeConfiguracion config){
    
    /*
     Load fichero PNG
     
     */
    
    std::vector<unsigned char> image;
    
    unsigned error = lodepng::decode(image, width, height, config.nombreFicheroTextura);
    
    // If there's an error, display it.
    if(error != 0)
    {
        std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
        
    }
    
    
    glGenTextures(1, &texturaId);
	glBindTexture(GL_TEXTURE_2D, texturaId);
    
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
    
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
        cout << "Error uploading texture. glError: 0x%04X" << err << endl;
    
 
    regiones = config.configuracion;
    
    
}

textcoord zeTextura::getRegionByNombre(string nombre){
    
    string datos = regiones[nombre];
    istringstream piezas(datos);
    textcoord region_data;
    float coord[4];
    int contador =0;
    
    
    //parseando fichero.
    while (piezas)
    {
        string s;
        if (!getline( piezas, s, ',' )) break;
        s.erase(std::remove(s.begin(), s.end(), ']'), s.end());
        s.erase(std::remove(s.begin(), s.end(), '['), s.end());
        
        cout << s << endl;
        
        coord[contador++] = atoi(s.c_str());
    }
    
    region_data.uvx1 = (float) coord[0] / width;
    region_data.uvx2 = (float) coord[1] / width;
    region_data.uvy1 = (float) coord[2] / height;
    region_data.uvy2 = (float) coord[3] / height;
    
    
    return region_data;
    
}



