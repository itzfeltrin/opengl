#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char *description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
float rgbV(int color) // function to convert 255 to 1.0
{
    return ((float)color * 0.39f) / 100;
}
int main(void)
{
    GLFWwindow *window;
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
        glClearColor(rgbV(103), rgbV(141), rgbV(230), 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glBegin(GL_QUADS); // grass
        glColor3f(rgbV(148), rgbV(173), rgbV(7));
        glVertex3f(-1.0f, -0.8f, 0.0f); // left-top
        glVertex3f(1.0f, -0.8f, 0.0f);  // right-top
        glVertex3f(1.0f, -1.0f, 0.0f);  // right-bottom
        glVertex3f(-1.0f, -1.0f, 0.0f); // left-bottom
        glEnd();

        glBegin(GL_QUADS); // building
        glColor3f(rgbV(232), rgbV(213), rgbV(151));
        glVertex3f(-0.9f, -0.2f, 0.0f); // left-top
        glVertex3f(0.1f, -0.2f, 0.0f);  // right-top
        glVertex3f(0.1f, -0.8f, 0.0f);  // right-bottom
        glVertex3f(-0.9f, -0.8f, 0.0f); // left-bottom
        glEnd();

        glBegin(GL_TRIANGLES); // roof
        glColor3f(rgbV(230), rgbV(125), rgbV(50));
        glVertex3f(-0.95f, -0.2f, 0.0f); // left-down
        glVertex3f(-0.4f, 0.25f, 0.0f);  // middle-top
        glVertex3f(0.15f, -0.2f, 0.0f);  // right-down
        glEnd();

        glBegin(GL_QUADS); // door
        glColor3f(rgbV(97), rgbV(42), rgbV(3));
        glVertex3f(-0.75f, -0.4f, 0.0f); // left-top
        glVertex3f(-0.55f, -0.4f, 0.0f); // right-top
        glVertex3f(-0.55f, -0.8f, 0.0f); // right-bottom
        glVertex3f(-0.75f, -0.8f, 0.0f); // left-bottom
        glEnd();

        glBegin(GL_QUADS); // window
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-0.35f, -0.4f, 0.0f); // left-top
        glVertex3f(-0.05f, -0.4f, 0.0f); // right-top
        glVertex3f(-0.05f, -0.6f, 0.0f); // right-bottom
        glVertex3f(-0.35f, -0.6f, 0.0f); // left-bottom
        glEnd();

        glBegin(GL_QUADS); // tree log
        glColor3f(rgbV(145), rgbV(111), rgbV(67));
        glVertex3f(0.65f, -0.8f, 0.0f); // left-top
        glVertex3f(0.7f, -0.8f, 0.0f);  // right-top
        glVertex3f(0.7f, -0.3f, 0.0f);  // right-bottom
        glVertex3f(0.65f, -0.3f, 0.0f); // left-bottom
        glEnd();

        glBegin(GL_TRIANGLES); // tree leaves
        glColor3f(rgbV(31), rgbV(89), rgbV(4));
        glVertex3f(0.55f, -0.3f, 0.0f); // left-down
        glVertex3f(0.675f, 0.2f, 0.0f); // middle-top
        glVertex3f(0.8f, -0.3f, 0.0f);  // right-down
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
