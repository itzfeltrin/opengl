#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Primitivas", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        //float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        
        glBegin(GL_QUADS);                      // Draw A Quad
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.5f, 0.5f, 0.0f);              // Top Left
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f( 0.5f, 0.5f, 0.0f);              // Top Right
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f( 0.5f,-0.5f, 0.0f);              // Bottom Right
        glColor3f(1.f, 1.f, 0.f);
        glVertex3f(-0.5f,-0.5f, 0.0f);              // Bottom Left
        glEnd();      
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
