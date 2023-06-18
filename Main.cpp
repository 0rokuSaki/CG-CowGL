/*****************************************************************//**
 * \file   Main.cpp
 * \brief  
 * 
 * *** BUILD INSTRUCTIONS (VS2019/VS2022 Windows 10/11) ***
 * 1. Setup OpenGL: https://www.geeksforgeeks.org/how-to-setup-opengl-with-visual-studio-2019-on-windows-10/.
 * 2. Select x86 Debug configuration.
 * 3. Build the solution (ctrl + shift + B).
 * 
 * \author aaron
 * \date   May 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <Windows.h>
#include <GL/glut.h>
#include <iostream>
#include "TopMenuScene.h"
#include "HelpMenuScene.h"
#include "AdjustAmbientLightMenuScene.h"
#include "MainScene.h"

#include <chrono>
#include <thread>

/******************************
*          DEFINES            *
*******************************/

/* Window */
#define WINDOW_INIT_POS  100, 100
#define WINDOW_INIT_SIZE 720, 480
#define WINDOW_TITLE     "CG GowGL"
#define WORLD_COORD       0.0, 100.0, 0.0, 100.0  // left right bottom top

/******************************
*     FUNCTION PROTOTYPES     *
*******************************/
void createWindow(int argc, char** argv);
void registerCallbacks(void);
void displayCallback(void);
void mouseCallback(int button, int state, int x, int y);
void keyboardCallback(unsigned char key, int x, int y);
void idleCallback(void);
void resetProjectionAndModelviewMatrices(void);
int main(int argc, char** argv);

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void createWindow(int argc, char** argv)
{
    /* Create the window */
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowPosition(WINDOW_INIT_POS);      // Set top-left window position
    glutInitWindowSize(WINDOW_INIT_SIZE);         // Set window width and height
    glutCreateWindow(WINDOW_TITLE);               // Create window

    /* Initialize the window */
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // Set window color to white
}


void registerCallbacks(void)
{
    glutDisplayFunc(displayCallback);
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);
    glutIdleFunc(idleCallback);
}


void displayCallback(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    renderTopMenuScene();
    renderMainScene();

    if (displayHelpMenu)
    {
        renderHelpMenuScene();
    }
    if (displayAdjustAmbientLightMenu)
    {
        renderAdjustAmbientLightScene();
    }
    
    glFlush();
}


void mouseCallback(int button, int state, int x, int y)
{
    handleMouseEventTopMenu(button, state, x, y);
    handleMouseEventAdjustAmbientLightMenu(button, state, x, y);
    glutPostRedisplay();
}


void keyboardCallback(unsigned char key, int x, int y)
{
    handleKeyboardEventHelpMenu(key, x, y);
    handleKeyboardEventAdjustAmbientLightMenu(key, x, y);
    glutPostRedisplay();
}

void idleCallback(void)
{
    static GLdouble theta = 270.0;
    static const GLdouble x = 15.0;
    static const GLdouble y = 15.0;

    viewOrigin.setX(cos(theta) * x);
    viewOrigin.setY(sin(theta) * y);

    renderMainScene();
    glutPostRedisplay();

    theta += 0.01;
    
    if (theta >= 360.0)
    {
        theta = 0.0;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}


void resetProjectionAndModelviewMatrices(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    /* Initialize OpenGL */
    createWindow(argc, argv);  // Create the display-window
    registerCallbacks();       // Assign callback functions for events
    glutMainLoop();            // Display everything and wait
    return 0;
}
