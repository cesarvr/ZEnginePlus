/*
 Cesar Valdez
 
*/

#ifdef GL_ES
precision mediump float;
#endif


varying vec3 a_color;


void main (void)
{
    
    
  //  vec4 text_color = texture2D(textura, textura_cord_out);
  //  vec4 cc = vec4(a_color,1.0);
    
 
    gl_FragColor = vec4(a_color,1.0);
	
    
}
