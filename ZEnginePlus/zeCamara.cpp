//
//  zeCamara.cpp
//  ZEnginePlus
//
//  Created by Cesar Luis Valdez on 15/09/13.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#include "zeCamara.h"
#include "glm.hpp"

zeCamara::zeCamara(glm::vec3 mPos_tmp, glm::vec3 mView_tmp, glm::vec3 mUp_tmp){

    proyeccion = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 300.0f);
 
    
    mPos = mPos_tmp;
    mView = mView_tmp;
    mUp = mUp_tmp;
    
    vista = glm::lookAt(mPos, mView, mUp);
    
    // Camera matrix
    
    /*
    vista       = glm::lookAt(
                              glm::vec3(2,5,43), // Camera is at (4,3,3), in World Space
                              glm::vec3(0,0,0), // and looks at the origin
                              glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                              );
    
*/
    
    desplazarCamara = glm::mat4(1.0f);

}




void zeCamara::rotarCamara(){

    vista = glm::rotate(vista, 0.05f, glm::vec3(0.0f,1.0f,0.0f));


}


void zeCamara::moverCamara(float speed){

    glm::vec3 vVector = mView - mPos;	// Get the view vector
	
	// forward positive camera speed and backward negative camera speed.
	mPos.x  = mPos.x  + vVector.x * speed;
	mPos.z  = mPos.z  + vVector.z * speed;
	mView.x = mView.x + vVector.x * speed;
	mView.z = mView.z + vVector.z * speed;

}


void zeCamara::rotarCamara(float speed){

    glm::vec3 vVector = mView - mPos;	// Get the view vector
    
	mView.z = (float)(mPos.z + sin(speed)*vVector.x + cos(speed)*vVector.z);
	mView.x = (float)(mPos.x + cos(speed)*vVector.x - sin(speed)*vVector.z);



}


void zeCamara::rotarPosicionCamara(float speed){

    glm::vec3 vVector = mPos - mView;
    
    mPos.z = (float)(mView.z + sin(speed)*vVector.x + cos(speed)*vVector.z);
	mPos.x = (float)(mView.x + cos(speed)*vVector.x - sin(speed)*vVector.z);


}

void zeCamara::update(){

    vista = glm::lookAt(mPos, mView, mUp);

    vista *= desplazarCamara;
    
    //reiniciar matrix.
   // desplazarCamara = glm::mat4(1.0f);
}



void zeCamara::desplazarDerecha(float speed){

    
    
    desplazarCamara = glm::translate(desplazarCamara, glm::vec3(speed*12,0.0f,0.0f));
    

}


void zeCamara::desplazarIzquierda(float speed){

    desplazarCamara = glm::translate(desplazarCamara, glm::vec3(speed*12,0.0f,0.0f));
    

}


void zeCamara::trackConCursor(float x, float y){
    
    int mid_x = 1240  >> 1;
	int mid_y = 840  >> 1;
    
    
    float angle_y  = 0.0f;
	float angle_z  = 0.0f;

	angle_y = (float)( (mid_x - x) ) / 100000;
	angle_z = (float)( (mid_y - y) ) / 100000;

    
    // The higher the value is the faster the camera looks around.
	mView.y += angle_z * 2;
    
	// limit the rotation around the x-axis
//	if(mView.y > 3.5f)		mView.y = 3.5f;
//	if(mView.y < 0.4f)		mView.y = 0.4f;
    
    zeCamara::rotarPosicionCamara(-angle_y);

}
