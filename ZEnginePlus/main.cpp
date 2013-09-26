
#include <iostream>
#include "glew.h"

#include "zeEscena.h"
//#include "ZEEscenaPrueba1.h"
#include "glfw3.h"

//zeEscena escena;


GLboolean ARRIBA = false;
GLboolean ABAJO = false;
GLboolean DERECHA = false;
GLboolean IZQUIERDA = false;



static void inicializarEngine(){
    printf("variables OpenGL\n");
    
	/*glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
    */
    /*
	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    glDepthRange(0.0f, 1.0f);
	/*glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
*/
    
    //glEnable(GL_DEPTH_TEST);
    //escena.iniciar();
}


void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    if (key == GLFW_KEY_A  && action == GLFW_PRESS) {
        IZQUIERDA = true;
    }else
        IZQUIERDA = false;
    
    if (key == GLFW_KEY_S && action == GLFW_PRESS ) {
        ABAJO = true;
    }else
        ABAJO = false;
    
    if (key == GLFW_KEY_D  && action == GLFW_PRESS) {
        DERECHA = true;
    }else
        DERECHA = false;
    
    if (key == GLFW_KEY_W  && action == GLFW_PRESS ) {
        ARRIBA = true;
    }else{
        ARRIBA = false;
    }

    
    
}




double calcFPS(double theTimeInterval = 1.0, GLFWwindow* window = NULL, std::string theWindowTitle = "NONE")
{
	// Static values which only get initialised the first time the function runs
	static double t0Value       = glfwGetTime(); // Set the initial time to now
	static int    fpsFrameCount = 0;             // Set the initial FPS frame count to 0
	static double fps           = 0.0;           // Set the initial FPS value to 0.0
    
	// Get the current time in seconds since the program started (non-static, so executed every time)
	double currentTime = glfwGetTime();
    
	// Ensure the time interval between FPS checks is sane (low cap = 0.1s, high-cap = 10.0s)
	// Negative numbers are invalid, 10 fps checks per second at most, 1 every 10 secs at least.
	if (theTimeInterval < 0.1)
	{
		theTimeInterval = 0.1;
	}
	if (theTimeInterval > 10.0)
	{
		theTimeInterval = 10.0;
	}
    
	// Calculate and display the FPS every specified time interval
	if ((currentTime - t0Value) > theTimeInterval)
	{
		// Calculate the FPS as the number of frames divided by the interval in seconds
		fps = (double)fpsFrameCount / (currentTime - t0Value);
        
		// If the user specified a window title to append the FPS value to...
		if (theWindowTitle != "NONE")
		{
			// Convert the fps value into a string using an output stringstream
			std::ostringstream stream;
			stream << fps;
			std::string fpsString = stream.str();
            
			// Append the FPS value to the window title details
			theWindowTitle += " | FPS: " + fpsString;
            
			// Convert the new window title to a c_str and set it
			const char* pszConstString = theWindowTitle.c_str();
			glfwSetWindowTitle(window, pszConstString);
		}
		else // If the user didn't specify a window to append the FPS to then output the FPS to the console
		{
			std::cout << "FPS: " << fps << std::endl;
		}
        
		// Reset the FPS frame counter and set the initial time to be now
		fpsFrameCount = 0;
		t0Value = glfwGetTime();
	}
	else // FPS calculation time interval hasn't elapsed yet? Simply increment the FPS frame counter
	{
		fpsFrameCount++;
	}
    
	// Return the current FPS - doesn't have to be used if you don't want it!
	return fps;
}


void cursorPosCallback( float x, float y) {
	printf("Cursor now at (%f,%f)", x, y);
}

#define SCREEN_ANCHO 1280
#define SCREEN_ALTO 720

int main(int argc, char **argv) {
    
    
    
    
    
    
	/* iniciando la movida*/
    
   // EscenaUno escena;

    
    
    
    if (!glfwInit())
    {
        printf("Error iniciando GLFW");
        exit(EXIT_FAILURE);
    }
    //manejador de errores;
    
    glfwSetErrorCallback(error_callback);
    
    GLFWwindow* window = glfwCreateWindow(SCREEN_ANCHO, SCREEN_ALTO, "ZombieEngine", NULL, NULL);
    
    
    
    if (!window)
    {
        
        printf("error al crear ventana.");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    double x,y;
    
    glfwSetKeyCallback(window, key_callback);
    
   // glfwGetCursorPos(window, &x,&y);

   glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    
    // Make the window's context current
    glfwMakeContextCurrent(window);

    
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }
    
    zeEscena escena;

    
    inicializarEngine();
    escena.iniciar();
    
    while (!glfwWindowShouldClose(window))
    {
        
       // cout << calcFPS() << endl;              // Print the FPS to the console once per second
        //cout << calcFPS(2.0) << endl;           // Print the FPS to the console every 2 seconds
        calcFPS(1.0,window, "Current FPS: ");
       
        
        if (ARRIBA) {
            escena.lookUp();
        }
        if (DERECHA) {
            escena.lookRight();
        }
        if (ABAJO) {
            escena.lookDown();
        }
        if (IZQUIERDA) {
            escena.lookLeft();
        }
        
        //printf("x-> %f y->%f \n", x,y);
        escena.trackCursor(x, y);
        
        /* Bucle principal 
  
        escena.update(0.14f);
        escena.render(); */
        escena.update(0.033f); 
        escena.render();
        
        glfwGetCursorPos(window, &x, &y);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
   // escena.bye();
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
	return 1;
    
}