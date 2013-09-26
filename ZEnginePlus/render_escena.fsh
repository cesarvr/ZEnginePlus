/*
 Cesar Valdez
 
*/

#ifdef GL_ES
precision mediump float;
#endif


varying vec2 textura_cord_out;
varying vec3 a_color;


//Uniforms.
uniform sampler2D textura;


void main (void)
{
    
    
    vec4 text_color = texture2D(textura, textura_cord_out);
    vec4 cc = vec4(a_color,1.0);

    gl_FragColor = text_color; //vec4(a_color,1.0);
	
    
}
