/*
 Cesar Valdez
 
 */

// Parametros
uniform mat4 cameraToClipMatrix;
uniform mat4 modelToCameraMatrix;

attribute vec3 position;
attribute vec3 color;
attribute vec2 textura_cord;


varying vec3 a_color;

void main()
{
    vec2 Textura = textura_cord;
    
    vec4 posicionv4 = modelToCameraMatrix *vec4(position, 1.0);
    gl_Position = cameraToClipMatrix * posicionv4;	

    a_color = color;
    
	//theColor = color;
    
}