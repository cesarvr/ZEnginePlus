
#include <iostream>
#include "glew.h"

#include "zeEscena.h"
#include "glfw3.h"

zeEscena escena;

GLboolean ARRIBA = false;
GLboolean ABAJO = false;
GLboolean DERECHA = false;
GLboolean IZQUIERDA = false;



static void inicializarEngine(){
    glEnable(GL_DEPTH_TEST);
  //glEnable(GL_CULL_FACE);

    escena.iniciar();
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


#define SCREEN_ANCHO 640
#define SCREEN_ALTO 480

int main(int argc, char **argv) {
    
    
    
    
    
    
	/* iniciando la movida*/
    
    
    

    
    
    
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
    
     glfwSetKeyCallback(window, key_callback);
    
    
   glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    
    // Make the window's context current
    glfwMakeContextCurrent(window);

    
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }
    
    
    
    inicializarEngine();
    
    while (!glfwWindowShouldClose(window))
    {
        
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
        
        
        /* Bucle principal  */
  
        escena.update(0.14f);
        escena.render();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
	return 1;
    
}