//
//  zeRender.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 12/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeRender.h"

GLint shdMvp, shdColor, shdPosicion, shdTexturaCord, texturaID;


zeRender::zeRender(){
/*
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

*/
    std::cout <<"iniciando"<<std::endl;
    
}

void zeRender::draw(zeTile tile){
    
    zombiShader.usarPrograma();
    
   /*glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tile.textura.texturaId);
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(texturaID, 0);
    */
    
    glUniformMatrix4fv(shdMvp, 1, GL_FALSE, &tile.mvp[0][0]);
    
    glBindBuffer(GL_ARRAY_BUFFER, tile.vertexBuffer.vertex_buffer);
    
    glVertexAttribPointer(shdPosicion,
                          POSITION_DATA_SIZE_IN_ELEMENTS,
                          GL_FLOAT,
                          false,
                          bytes_bloques,
                          (void *)0);
    
    
    glEnableVertexAttribArray(shdPosicion);
    
    
    /**
     COLOR**/
    
    glVertexAttribPointer(shdColor,
                          COLOR_DATA_SIZE_IN_ELEMENTS,
                          GL_FLOAT,
                          false,
                          bytes_bloques,
                          (void *)(POSITION_DATA_SIZE_IN_ELEMENTS * SIZE_FLOAT_DATA));
    
    glEnableVertexAttribArray(shdColor);
    
    
    
    glVertexAttribPointer(shdTexturaCord,
                          TEXTURA_CORD_DATA_SIZE_IN_ELEMENTS,
                          GL_FLOAT,
                          false,
                          bytes_bloques,
                          (void *)((POSITION_DATA_SIZE_IN_ELEMENTS+COLOR_DATA_SIZE_IN_ELEMENTS) * SIZE_FLOAT_DATA));
    
    glEnableVertexAttribArray(shdTexturaCord);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tile.vertexBuffer.indices_buffer);
    
    glDrawElements(GL_TRIANGLE_STRIP, tile.vertexBuffer.cantidad_indices, GL_UNSIGNED_SHORT, 0);
    
    

}


void zeRender::limpiar(){

    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

}

void zeRender::volcarBuffer(){

//glutSwapBuffers();

}


void zeRender::setShader(zeShader shader){

    zombiShader = shader;
    // shaders
    
    
    shdMvp         = zombiShader.getUniform("modelViewProjMatrix");
    shdColor       = zombiShader.getParametros("color");        // :@"color"];
    shdTexturaCord = zombiShader.getParametros("textura_cord"); // :@"textura_cord"];
    shdPosicion    = zombiShader.getParametros("position");     // :@"position"];
    texturaID      = zombiShader.getUniform("textura");   //(programID, "myTextureSampler");

    
}
