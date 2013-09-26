//
//  zeShader.h
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 15/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __ZEnginePlus__zeShader__
#define __ZEnginePlus__zeShader__

#include <iostream>
#include <fstream>
#include <sstream>
#include "zeImport.h"


class zeShader {
protected:
    GLuint      ShaderProgram;
    std::string loadFicheroShader( std::string nombreFichero );
    GLuint      compilarShader( std::string shader, GLenum tipoShader );
    bool        linkarPrograma( GLuint prog );
    
    
public:
    
    void       cargarShader(std::string shader, std::string path);
    GLuint     getUniform(const char *uniformNombre );
    GLuint     getParametros(const char *parametros );
    void       usarPrograma();
    void       soltarPrograma();
    
    
    
};


#endif /* defined(__ZEnginePlus__zeShader__) */
