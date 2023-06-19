/*****************************************************************//**
 * \file   renderTopMenu.cpp
 * \brief  Function definitions for rendering top menu.
 * 
 * \author aaron
 * \date   June 2023
 *********************************************************************/

/******************************
*          INCLUDES           *
*******************************/
#include <GL/glut.h>
#include "renderTopMenu.h"
#include "renderHelpMenu.h"
#include "AdjustAmbientLightMenuScene.h"

/******************************
*       GLOBAL VARIABLES      *
*******************************/
const GLint TOP_MENU_HEIGHT = 30;

const GLint EXIT_BTN_WIDTH = 45;
const GLint HELP_BTN_WIDTH = 50;
const GLint ADJ_LIGHTING_BTN_WIDTH = 165;
const GLint BTN_HEIGHT = TOP_MENU_HEIGHT;

Button exitBtn(0, 0, EXIT_BTN_WIDTH, BTN_HEIGHT, "Exit");
Button helpBtn(0, 0, HELP_BTN_WIDTH, BTN_HEIGHT, "Help");
Button adjAmbLightBtn(0, 0, ADJ_LIGHTING_BTN_WIDTH, BTN_HEIGHT, "Adjust Lighting");

/******************************
*     FUNCTION DEFINITIONS    *
*******************************/
void renderTopMenu(void)
{
    static const GLint TOP_MENU_FRAME_WIDTH = 3;

    const GLint windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    /* Render a frame for the top menu */
    glViewport(0, windowHeight - TOP_MENU_HEIGHT, windowWidth, TOP_MENU_HEIGHT);

    resetProjectionAndModelviewMatrices();

    gluOrtho2D(0.0, windowWidth, windowHeight - TOP_MENU_HEIGHT, windowHeight);

    glRectf(0.0, 0.0, windowWidth, TOP_MENU_HEIGHT);
    
    glColor3d(RGB_COLOR_BLACK);
    glLineWidth(TOP_MENU_FRAME_WIDTH);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1.0, windowHeight - TOP_MENU_HEIGHT + 1.0);
    glVertex2d(windowWidth, windowHeight - TOP_MENU_HEIGHT + 1.0);
    glVertex2d(windowWidth, windowHeight);
    glVertex2d(1.0, windowHeight);
    glEnd();

    /* Render buttons */
    exitBtn.setPosition(0, windowHeight - BTN_HEIGHT);
    helpBtn.setPosition(EXIT_BTN_WIDTH, windowHeight - BTN_HEIGHT);
    adjAmbLightBtn.setPosition(EXIT_BTN_WIDTH + HELP_BTN_WIDTH, windowHeight - BTN_HEIGHT);

    exitBtn.render();
    helpBtn.render();
    adjAmbLightBtn.render();
}


void handleMouseEventTopMenu(int button, int state, int x, int y)
{
    const GLint windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    y = windowHeight - y;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (exitBtn.clicked(x, y))
        {
            exit(0);
        }
        else if (helpBtn.clicked(x, y))
        {
            displayHelpMenu = true;
            displayAdjustAmbientLightMenu = false;
        }
        else if (adjAmbLightBtn.clicked(x, y))
        {
            displayHelpMenu = false;
            displayAdjustAmbientLightMenu = true;
        }
    }
}
