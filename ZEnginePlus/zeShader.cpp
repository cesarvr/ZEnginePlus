//
//  zeShader.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 15/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeShader.h"


bool TODO_CORRECTO = true;

void zeShader::cargarShader(std::string shader, std::string path){

    std::string fragment, vertex;
    GLuint vertex_shader,fragment_shader;

    if (TODO_CORRECTO) {
        vertex   = zeShader::loadFicheroShader(path+shader+".vsh"  );
        fragment = zeShader::loadFicheroShader(path+shader+ ".fsh" );
        
    }

    
    // Create shader program.
    ShaderProgram = glCreateProgram();
    
    if (ShaderProgram == 0) {
        fprintf(stderr, "Error creating shader program\n");
        TODO_CORRECTO = false;
    }

    
    

        std::cout << std::endl << "iniciando compilacion de los shader"<< std::endl;
        
        vertex_shader   = zeShader::compilarShader(vertex, GL_VERTEX_SHADER);
        fragment_shader = zeShader::compilarShader(fragment, GL_FRAGMENT_SHADER);
        
        std::cout << std::endl << "iniciando compilacion de los shader [fin]"<< std::endl;

    
    

    
    
    // Attach vertex shader to program.
    glAttachShader(ShaderProgram, vertex_shader);
    
    // Attach fragment shader to program.
    glAttachShader(ShaderProgram, fragment_shader);
    
    if (!zeShader::linkarPrograma(ShaderProgram)) {
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
        glDeleteProgram(ShaderProgram);
        
        std::cout << "Errror al linkar" << std::endl;
    }
    

    std::cout << "añadiendo shaders al programa principal." << std::endl;
    
    
    // Release vertex and fragment shaders.
    if (vertex_shader) {
        glDetachShader(ShaderProgram, vertex_shader);
        glDeleteShader(vertex_shader);
    }
    if (fragment_shader) {
        glDetachShader(ShaderProgram, fragment_shader);
        glDeleteShader(fragment_shader);
    }


}


GLuint zeShader::compilarShader(std::string source, GLenum tipoShader ){

    GLint status;
    GLuint shader;


    
    if (source == "") {
        std::cout << "fichero vacio / o inexistente.";
        TODO_CORRECTO = false;
    }
    
   const char *data_src =  source.c_str();
    
    shader = glCreateShader(tipoShader);
    glShaderSource(shader, 1,&data_src, NULL);
    glCompileShader(shader);
    
    
    
    /*  Ha funcionado ? */
    
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(shader, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", shader, InfoLog);
        exit(1);
    }

    
#if defined(DEBUG)
    GLint logLength;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetShaderInfoLog(shader, logLength, &logLength, log);
        std::cout << "Shader compile log: "<< log << std::endl;
        free(log);
    }
#endif
    
    /* fin comprobaciones */ 
    
    
    
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == 0) {
        glDeleteShader(shader);
        TODO_CORRECTO = false;
    }
    
    return shader;



}


bool zeShader::linkarPrograma( GLuint prog ){

    GLint status;
    glLinkProgram(prog);
    
#if defined(DEBUG)
    GLint logLength;
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetProgramInfoLog(prog, logLength, &logLength, log);
        std::cout << "linkando programa: "<< log << std::endl;
        free(log);
    }
#endif
    
    glGetProgramiv(prog, GL_LINK_STATUS, &status);
    if (status == 0) {
        return false;
    }
    
    return true;
    


}


GLuint zeShader::getUniform(const char *uniformNombre){
    GLuint temp =  glGetUniformLocation(ShaderProgram, uniformNombre);
    
    
    assert(temp != 0xFFFFFFFF);
    
    return temp;


}

GLuint zeShader::getParametros(const char *parametros){


    //NSLog(@"Uniform parametros: %@",param);
    GLuint temp =  glGetAttribLocation(ShaderProgram, parametros);

    assert(temp != 0xFFFFFFFF);
    
    return temp;

}

std::string zeShader::loadFicheroShader(std::string nombreFichero){

    printf("[fichero de configuracion [cargando..]]");
    
    
    std::ifstream inFichero(nombreFichero);
    
    std::string line, data;
    
    while(getline(inFichero, line)) {
        
        data.append(line + " \n ");
        
    }




    return data;

}


void zeShader::usarPrograma(){
    
    glUseProgram(ShaderProgram);
    
}
