/*
 Cesar Valdez
 
 */

// Parametros
uniform mat4 modelViewProjMatrix;


attribute vec3 position;
attribute vec3 color;
attribute vec2 textura_cord;

//Para el Fragment
varying vec2 textura_cord_out;
varying vec3 a_color;

void main(void)
{
	gl_Position = modelViewProjMatrix * vec4(position,1.0);
    textura_cord_out = textura_cord;
    a_color = color;
}