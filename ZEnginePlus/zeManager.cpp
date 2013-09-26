//
//  zeManager.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 13/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeManager.h"


enum RegionesConfig {
    COLECCION,
    ARREGLO,
    ERROR_LECTURA,
    COMENTARIO_INI,
    COMENTARIO_FIN
    
};

std::map <std::string, std::string> regiones2d;
std::map<std::string, Region4> regiones_cubo;
std::vector<std::string> listadoFicherosTextura;

//crear objeto textura.

void zeConfiguracion::cargarTextura(string pathFicheroTextura){

    if (pathFicheroTextura == "") {
        printf("ruta incorrecta revisar fichero de configuracion.");
    }
    assert(pathFicheroTextura != "");

    texturaObj.cargarTexturasGL(pathFicheroTextura);

}

void zeConfiguracion::guardarArreglo(std::string line){
    std::string key, currValue;
    size_t posicion_separador = line.find(":");
    
    if (posicion_separador !=std::string::npos) {
        key = line.substr(0, posicion_separador);
        currValue = line.substr(posicion_separador + 1, (line.length() - posicion_separador));
        
        if ( key == "path" )
            nombreFicheroTextura = currValue;
        else if ( key == "texturas")
            zeConfiguracion::cargarTextura(nombreFicheroTextura+currValue);
        else
            regiones2d[key] = currValue;
    }
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}



textcoord zeConfiguracion::convertirATexturaCord(float * coord){

    textcoord region_data;
    
    region_data.uvx1 = (float) coord[0] / texturaObj.width;
    region_data.uvx2 = (float) coord[1] / texturaObj.width;
    region_data.uvy1 = (float) coord[2] / texturaObj.height;
    region_data.uvy2 = (float) coord[3] / texturaObj.height;


    return region_data;
}


Region4 zeConfiguracion::generarRegion4(std::vector<std::string> listaDeArreglos){
    
    Region4 region4;
    int lado = 0;
    
    for(std::string arreglo : listaDeArreglos){
        
        
        arreglo.erase(arreglo.find("["),1);
        arreglo.erase(arreglo.find("]"),1);
        std::stringstream flujo(arreglo);
        
        std::string temporal;
        
        float coord[4];
        int cnt = 0;
        
        while (std::getline(flujo, temporal, ',')) {
            
            assert(cnt < 4);
            coord[cnt]  = atof(temporal.c_str());
            cnt++;
            
        }
        
         std::cout << " coord[0]: " <<  coord[0] << std::endl;
         std::cout << " coord[1]: " <<  coord[1] << std::endl;
         std::cout << " coord[2]: " <<  coord[2] << std::endl;
         std::cout << " coord[3]: " <<  coord[3] << std::endl;
        

        
        lado++;
        
        if (lado == 1) {
            region4.izquierda =  zeConfiguracion::convertirATexturaCord(coord);
        }
        
        if (lado == 2) {
            region4.arriba =     zeConfiguracion::convertirATexturaCord(coord);
        }
        
        if (lado == 3) {
            region4.centro =     zeConfiguracion::convertirATexturaCord(coord);
        }
        
        if (lado == 4) {
            region4.abajo =      zeConfiguracion::convertirATexturaCord(coord);
        }
        if (lado == 5) {
            region4.derecha =    zeConfiguracion::convertirATexturaCord(coord);
        }
        if (lado == 6) {
            region4.atras =      zeConfiguracion::convertirATexturaCord(coord);
        }
        
    }
    
    return region4;
}



textcoord zeConfiguracion::getRegion2DByNombre(string nombre){

    string datos = regiones2d[nombre];
    istringstream piezas(datos);
    float coord[4];
    int contador = 0;
    
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
    
    return zeConfiguracion::convertirATexturaCord(coord);;
}


Region4 zeConfiguracion::getRegion4ByNombre(string nombre){

    return regiones_cubo[nombre];
}

void zeConfiguracion::guardarColeccion(std::string line){
    
    std::string key, data;
    size_t arreglo_inicio = line.find(":{");
    size_t primer_parentesis = line.find("{");
    size_t segundo_parentesis = line.find("}");
    
    std::vector<std::string> temporal;
    
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    
    key = line.substr( 0, arreglo_inicio );
    std::cout << "key: " << key << std::endl;
    
    data = line.substr( primer_parentesis+1, segundo_parentesis-1 );
    std::cout << "data: " << data << std::endl;
    
    split(data, '|', temporal);
    
    std::cout << "==============================" << std::endl;

    regiones_cubo[key] = zeConfiguracion::generarRegion4(temporal);
    
}

RegionesConfig leerCabecera(std::string linea){
    
    if (linea.find(":{") != std::string::npos) {
        return COLECCION;
    }
    
    if (linea.find(":") != std::string::npos) {
        return ARREGLO;
    }
    
    if (linea.find("/*") != std::string::npos) {
        return COMENTARIO_INI;
    }
    
    if (linea.find("*/") != std::string::npos) {
        return COMENTARIO_FIN;
    }
    
    return ERROR_LECTURA;
}


zeConfiguracion::zeConfiguracion(string nombreFicheroConfiguracion){


    printf("fichero: %s ", nombreFicheroConfiguracion.c_str());
    if (nombreFicheroConfiguracion == "") {
        printf("error fichero de configuracion not found");
    }
    assert(nombreFicheroConfiguracion != "");
    
    //cargando fichero de configuraciones.
    std::ifstream inFichero(nombreFicheroConfiguracion);
    std::string line;
    bool ignorar = false;
    while(getline(inFichero, line)) {
        
        RegionesConfig config = leerCabecera(line);
        
        if (config == COMENTARIO_INI) {
            ignorar = true;
        }else if (config == COMENTARIO_FIN){
            ignorar = false;
        }else if(config == ARREGLO && !ignorar)
            guardarArreglo(line);
        else if (config == COLECCION && !ignorar)
            guardarColeccion(line);
        else if (config == ERROR_LECTURA && !ignorar)
            printf("Error revisar fichero de configuracion \n");
    }

}

void zeTextura::cargarTexturasGL(string pathFicheroImagen){
    
 
    // Load fichero PNG
    
    std::vector<unsigned char> image;
    
    unsigned error = lodepng::decode(image, width, height, pathFicheroImagen);
    
    // If there's an error, display it.
    if(error != 0)
    {
        std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
        
    }

    glGenTextures(1, &texturaId);
	glBindTexture(GL_TEXTURE_2D, texturaId);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); //if the texture is smaller, than the image, we get the avarege of the pixels next to it
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
    
    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
        cout << "Error uploading texture. glError: 0x%04X" << err << endl;
 
    
}



